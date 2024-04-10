#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
#define int ll

const int maxn = 5e5;
const int mod = 998244353;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

void add(int &x, int y) {
    x += y;
    if(x >= mod) {
        x -= mod;
    }
}

int n, k, dp[501][501][2], sum[501][501][2], ans;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for(int n = 1; n <= 500; n++)
        for(int l = 1; l <= n; l++) {
            for(int x = 1; x < l; x++) {
                add(dp[n][l][0], dp[n - x][l][1]);
                add(dp[n][l][1], dp[n - x][l][0]);
            }
            for(int x = 0; x <= min(n - l, l); x++) {
                add(dp[n][l][0], dp[n - l][x][1]);
                add(dp[n][l][1], dp[n - l][x][0]);
            }
        }
    //cout << dp[2][1][0] << '\n';
    for(int n = 1; n <= 500; n++)
        for(int l = 1; l <= n; l++)
            for(int bit = 0; bit < 2; bit++) {
                sum[n][l][bit] = sum[n][l - 1][bit];
                add(sum[n][l][bit], dp[n][l][bit]);
            }
    cin >> n >> k;
    for(int l = 1; l <= min(n, k); l++) {
        int x = dp[n][l][0];
        add(x, dp[n][l][1]);
        ans = (ans + 1LL * x * sum[n][min(n, (k + l - 1) / l - 1)][0]) % mod;
    }
    cout << ans;
}