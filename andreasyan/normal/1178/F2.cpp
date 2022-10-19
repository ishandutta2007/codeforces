#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1003, MM = 1000006, M = 998244353;

int n, m;
int a[MM];

vector<int> v[N];

int dp[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    vector<int> vv;
    for (int i = 1; i <= m; ++i)
    {
        if (a[i] != a[i - 1])
            vv.push_back(a[i]);
    }
    m = vv.size();
    for (int i = 1; i <= m; ++i)
        a[i] = vv[i - 1];
    if (m > n * 2)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        v[a[i]].push_back(i);
    }
    for (int l = 1; l <= m + 1; ++l)
        dp[l][l - 1] = 1;
    for (int d = 1; d <= m; ++d)
    {
        for (int l = 1; l <= m - d + 1; ++l)
        {
            int r = l + d - 1;
            int minu = N;
            for (int i = l; i <= r; ++i)
            {
                if (a[i] < minu)
                {
                    minu = a[i];
                }
            }
            if (!(l <= v[minu][0] && v[minu].back() <= r))
            {
                continue;
            }
            int rr = 0;
            for (int i = v[minu].back(); i <= r; ++i)
            {
                rr = (rr + dp[v[minu].back() + 1][i] * 1LL * dp[i + 1][r]) % M;
            }
            int ll = 0;
            for (int i = v[minu][0]; i >= l; --i)
            {
                ll = (ll + dp[i][v[minu][0] - 1] * 1LL * dp[l][i - 1]) % M;
            }
            int mm = 1;
            for (int i = 0; i < (int)v[minu].size() - 1; ++i)
                mm = (mm * 1LL * dp[v[minu][i] + 1][v[minu][i + 1] - 1]) % M;
            dp[l][r] = (((ll * 1LL * rr) % M) * 1LL * mm) % M;
        }
    }
    printf("%d\n", dp[1][m]);
    return 0;
}