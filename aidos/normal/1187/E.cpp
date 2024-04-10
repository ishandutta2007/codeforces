#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
int n;
vector<int> g[maxn];
long long sz[maxn];
long long sum[maxn];
void dfs(int v, int p) {
    sz[v] = 1;
    for(int to: g[v]) {
        if(to != p) {
            dfs(to, v);
            sz[v] += sz[to];
            sum[v] += sum[to] + sz[to];
        }
    }
}
long long ans = 0;
void dfs2(int v, int p, long long cur) {
    ans = max(ans, sum[v] + cur + n);
    for(int to: g[v]) {
        if(to != p) {
            dfs2(to, v, cur + (sum[v] - sum[to] - sz[to]) + n-sz[to]);
        }
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    dfs2(1, -1, 0);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}