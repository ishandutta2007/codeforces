#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 123;
const int mod = 1e9 + 7;
int n, k;
ll t;
int a[maxn];
vector<int> g[maxn], gr[maxn];
int used[maxn];
int b[maxn];
int dp[maxn];
void dfs(int v, int sum) {
    t -= sum;
    used[v] = 1;
    b[v] = a[v] + sum;
    for(int to: g[v]) {
        if(!used[to]){
            dfs(to, sum + a[v]);
        }
    }
}
void solve() {
    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i] && gr[i].size()==0) {
            dfs(i, 0);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            cout << 0 << "\n";
            return;
        }
    }
    if(t < 0) {
        cout << 0 << "\n";
        return;
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = b[i]; j <= t; j++) {
            dp[j] = (dp[j] + dp[j - b[i]]) % mod;
        }
    }
    cout << dp[t] << "\n";
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