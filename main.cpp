#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int v[5];
    v[0] = 1;
    v[1] = 5;
    v[2] = 10;
    v[3] = 25;
    v[4] = 50;

    unsigned long long d[5][30001];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 30001; j++)
        {
            d[i][j] = 0;
        }
    }

    d[0][0] = 1;

    for (int i = 0; i < 30000; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = j; k < 5; k++)
            {
                if (i + v[k] <= 30000)
                {
                    d[k][i + v[k]] += d[j][i];
                }
            }
        }
    }

    int n;
    while (cin >> n)
    {
        unsigned long long ans = 0;
        for (int i = 0; i < 5; i++)
            ans += d[i][n];

        if (ans > 1)
            cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n << " cents change.\n";
    }

    return 0;
}
