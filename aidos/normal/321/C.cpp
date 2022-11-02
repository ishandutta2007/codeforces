#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int n, m;
vector<int> g[maxn];
int del[maxn];
vector<int> ord;
int mx[maxn];
int sz[maxn];
vector< pair<int, int> > C[maxn];
void dfs(int v, int p) {
    sz[v] = 1;
    mx[v] = 0;
    ord.push_back(v);
    for(int to: g[v]) {
        if(del[to]) continue;
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        mx[v] = max(mx[v], sz[to]);
    }
}
char ans[maxn];
void rec(int v, char t) {
    ord.clear();
    dfs(v, -1);
    int c = v;
    for(int to: ord) {
        if(max((int)ord.size() - sz[to], mx[to]) < max((int)ord.size() - sz[c], mx[c]) ) {
            c = to;
        }
    }
    ans[c] = t;

    del[c] = 1;
    for(int to: g[c]) {
        if(!del[to]) rec(to, t+1);
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
    rec(1, 'A');
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
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