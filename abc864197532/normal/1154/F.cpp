#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500005, logN = 18, K = 600, C = 100, M = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    n = k;
    a.resize(n);
    vector <lli> pre(n + 1, 0);
    fop (i,0,n) pre[i + 1] = pre[i] + a[i];
    vector <int> b(n + 1, -1);
    fop (i,0,m) {
        cin >> x >> y;
        if (x > n) continue;
        b[x] = max(b[x], y);
    }
    vector <lli> dp(n + 1, 1ll << 60);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a[i - 1];
        for (int j = 1; i - j >= 0; ++j) if (b[j] != -1) {
            dp[i] = min(dp[i], dp[i - j] + pre[i] - pre[i - j + b[j]]);
        }
    }
    cout << dp[n] << endl;
}