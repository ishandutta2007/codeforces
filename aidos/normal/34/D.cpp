#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
int n, m;
int p[maxn];
vector<int> g[maxn];
void dfs(int v, int pa) {
    p[v] = pa;
    for(int to: g[v]) {
        if(to != pa) dfs(to, v);
    }
}
void solve() {
    int r1, r2;
    cin >> n >> r1 >> r2;

    for(int i = 1; i <= n; i++) {
        if(i == r1) continue;
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(r2, 0);
    for(int i = 1; i <= n; i++) {
        if(i != r2) cout << p[i] << " ";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}