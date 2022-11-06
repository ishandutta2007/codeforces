#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int)1e5 + 9;
char str[MxN + 9];
ll dp[MxN + 9];

ll f() {
    int n, p, k, x, y;
    cin >> n >> p >> k >> (str + 1) >> x >> y;
    for(int i = n; i >= 1; --i)
        dp[i] = (str[i] == '1' ? 0 : x) + (i + k > n ? 0 : dp[i+k]);

    ll ans = (ll)1e18;
    for(int i = p; i <= n; ++i) {
        ans = min(ans, dp[i] + (i - p) * 1LL * y);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll res = f();
        cout << res << '\n';
    }
    return 0;
}