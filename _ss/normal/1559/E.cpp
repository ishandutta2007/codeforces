#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10, mod =  998244353;
int n, m, L[N], R[N], dp[2][N];

void add(int &x, int y)
{
    x += y;
    if (x >= mod) x -= mod;
}

ll cal(int d)
{
    int W = m / d;
    for (int i = 0; i <= W; ++i) dp[0][i] = dp[1][i] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int l = (L[i] - 1) / d + 1, r = R[i] / d, nw = (i & 1), prv = nw ^ 1;
        if (l > r) return 0;
        dp[nw][0] = 0;
        for (int j = 1; j <= W; ++j)
        {
            dp[nw][j] = dp[nw][j - 1];
            if (l <= j) add(dp[nw][j], dp[prv][j - l]);
            if (r + 1 <= j) add(dp[nw][j], mod - dp[prv][j - r - 1]);
        }
    }
    int res = 0;
    for (int i = 0; i <= W; ++i) add(res, dp[n & 1][i]);
    return res;
}

int ans[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> L[i] >> R[i];
    for (int i = 1; i <= m; ++i) ans[i] = cal(i);
    for (int i = m; i; --i)
        for (int j = 2 * i; j <= m; j += i) add(ans[i], mod - ans[j]);
    cout << ans[1];
    return 0;
}