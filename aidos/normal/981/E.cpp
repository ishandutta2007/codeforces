#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
int n, q;
int dp[maxn];
vector<int> g[maxn];
int c[maxn];
void del(int x) {
    for(int i = x; i <= n; i++) {
        dp[i] = (dp[i] - dp[i - x] + mod) % mod;
    }
}
void add(int x) {
    for(int i = n; i >= x; i--) {
        dp[i] = (dp[i] + dp[i - x]) % mod;
    }
}
void solve() {
    cin >> n >> q;
    dp[0] = 1;
    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        g[l].push_back(x);
        g[r+1].push_back(-x);
    }
    for(int i = 1; i <= n; i++) {
        for(int x: g[i]) {
            if(x < 0) del(-x);
            else add(x);
        }
        for(int j = 1; j <= n; j++) {
            if(dp[j] != 0) c[j] = 1;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(c[i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int x: ans) {
        cout << x << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}