#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long M = 1000000007;

int n, k;
vector<int> a[N];

int z;
int c[N];
void dfs(int x)
{
    c[x] = z;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

long long dp[N][2], ndp[N][2];
long long sum[N][2];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0)
        {
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!c[i])
        {
            ++z;
            dfs(i);
        }

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
    }

    for (int ii = 0; ii < k - 1; ++ii)
    {
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= n; ++i)
        {
            sum[c[i]][0] += dp[i][0];
            sum[c[i]][0] %= M;
            sum[c[i]][1] += dp[i][1];
            sum[c[i]][1] %= M;
        }
        long long ysum0 = 0, ysum1 = 0;
        for (int i = 1; i <= z; ++i)
        {
            ysum0 += sum[i][0];
            ysum0 %= M;
            ysum1 += sum[i][1];
            ysum1 %= M;
        }
        for (int i = 1; i <= n; ++i)
        {
            ndp[i][0] = sum[c[i]][0];
            ndp[i][1] = (ysum1 + (ysum0 - sum[c[i]][0]) + M) % M;
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += dp[i][1];
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}