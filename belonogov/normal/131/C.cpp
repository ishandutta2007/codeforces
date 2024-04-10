#include <iostream>

using namespace std;
long long a[100][100];

int main()
{
    long long i, j, n, m, t, ans = 0;
    a[0][0] = 1;
    for (i = 1; i < 40; i++)
        for (j = 0; j <= i; j++)
        {
            a[i][j] = a[i - 1][j];
            if (j)
                a[i][j] += a[i - 1][j - 1];
        }
    cin >> n >> m >> t;
    t -= 5;
    for (i = 0; i <= t; i++)
    {
        ans += a[n][i + 4] * a[m][t - i + 1];
    }
    cout << ans;


    return 0;
}