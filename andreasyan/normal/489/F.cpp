#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 503;

int n, m, M;

int dp[N][N];
bool c[N][N];

int rec(int q0, int q1)
{
    if (c[q0][q1])
        return dp[q0][q1];
    c[q0][q1] = true;
    if ((n - q0 - q1) == n)
        return dp[q0][q1] = 1;
    if (q0 >= 2)
        dp[q0][q1] = (dp[q0][q1] + (((q0 * (q0 - 1)) / 2) * 1LL * rec(q0 - 2, q1 + 2)) % M) % M;
    if (q1 >= 2)
        dp[q0][q1] = (dp[q0][q1] + (((q1 * (q1 - 1)) / 2) * 1LL * rec(q0, q1 - 2)) % M) % M;
    if (q0 >= 1 && q1 >= 1)
        dp[q0][q1] = (dp[q0][q1] + (((q0 * q1) * 1LL * rec(q0 - 1, q1)) % M)) % M;
    return dp[q0][q1];
}

int q[N];
int main()
{
    scanf("%d%d%d", &n, &m, &M);
    for (int i = 0; i < m; ++i)
    {
        char a[N];
        scanf(" %s", a);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == '1')
                q[i]++;
        }
    }
    int q0 = 0, q1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (q[i] == 0)
            ++q0;
        else if (q[i] == 1)
            ++q1;
    }
    printf("%d\n", rec(q0, q1));
    return 0;
}