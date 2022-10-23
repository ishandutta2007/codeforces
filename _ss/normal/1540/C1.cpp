#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e4 + 10;
ll mod = 1e9 + 7;
int n, c[N], b[N], lim_sum[N], sc[N];
ll dp[110][N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i], sc[i] = sc[i - 1] + c[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    int q, x;
    cin >> q >> x;
    lim_sum[1] = x;
    for (int i = 2; i <= n; ++i) x += b[i - 1], lim_sum[i] = lim_sum[i - 1] + x;
    for (int i = 1; i <= n; ++i) lim_sum[i] = max(lim_sum[i], 0);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = lim_sum[i - 1]; j <= sc[i - 1]; ++j)
            for (int add = 0; add <= c[i]; ++add)
            {
                dp[i][j + add] += dp[i - 1][j];
                if (dp[i][j + add] >= mod) dp[i][j + add] -= mod;
            }
    ll res = 0;
    for (int j = lim_sum[n]; j <= sc[n]; ++j) res = (res + dp[n][j]) % mod;
    cout << res;
    return 0;
}