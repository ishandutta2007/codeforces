#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, s;
vector<int> g[maxn];
vector<int> gr[maxn], ord;
int u[maxn];
int c[maxn];
void dfs(int v) {
    c[v] = 1;
    u[v] = 1;
    for(int to: g[v]) {
        if(c[to] == 0) {
            dfs(to);
        }
    }
}
void dfs2(int v) {
    u[v] = 1;
    for(int to: g[v]) {
        if(!u[to]) {
            dfs2(to);
        }
    }
    ord.emplace_back(v);
}
void solve() {
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        gr[y].emplace_back(x);
    }
    dfs(s);
    for(int i = 1; i <= n; i++) {
        if(!u[i]) dfs2(i);
    }
    reverse(ord.begin(), ord.end());
    int ans = 0;
    for(int to: ord) {
        if(c[to] == 0) {
            dfs(to);
            ++ans;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
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