#include <bits/stdc++.h>
using namespace std;
const int N = 22, M = 100005, INF = 1000000009;

int m, n;
char a[M];

int q[N][N];

int dp[1 << N];
int main()
{
    scanf("%d%d", &m, &n);
    scanf(" %s", a);
    for (int i = 0; i < m - 1; ++i)
    {
        q[a[i] - 'a'][a[i + 1] - 'a']++;
        q[a[i + 1] - 'a'][a[i] - 'a']++;
    }
    for (int x = 1; x < (1 << n); ++x)
        dp[x] = INF;
    for (int x = 0; x < (1 << n) - 1; ++x)
    {
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++m;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                int q1 = 0;
                for (int j = 0; j < n; ++j)
                {
                    if ((x & (1 << j)))
                        q1 += q[i][j];
                }
                int q0 = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (!(x & (1 << j)) && j != i)
                        q0 += q[i][j];
                }
                int y = (x | (1 << i));
                dp[y] = min(dp[y], dp[x] + q1 * m - q0 * m);
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}