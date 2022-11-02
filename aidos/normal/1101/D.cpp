#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
int a[maxn];
vector<int> d[maxn];
vector<int> g[maxn];
vector<pii> dp[maxn];
int ans = 0;
void dfs(int v, int p) {
    int x = a[v];
    for(const int &pr: d[x]) {
        dp[v].emplace_back(make_pair(pr, 1));
    }
    for(const int &to: g[v]) {
        if(to == p) continue;
        dfs(to, v);
        for(pii &t: dp[v]) {
            for(pii &z: dp[to]) {
                if(t.first == z.first) {
                    ans = max(ans, t.second + z.second);
                    t.second = max(z.second + 1, t.second);
                }
            }
        }
    }
    for(pii &t: dp[v]) ans = max(ans, t.second);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i < maxn; i++) {
        if(d[i].size() == 0) {
            for(int j = i; j < maxn; j += i) {
                d[j].emplace_back(i);
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}