#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e2 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, m;
int p[maxn];
int u[maxn];
vector<int> g[maxn];
pair<int, int> w;
int found;
vector<int> cycle;

void dfs(int v, int pa) {
    u[v] = 1;
    p[v] = pa;
    for(int to: g[v]) {
        if(u[to] == 0) {
            dfs(to, v);
        } else if(u[to] == 1){
            if(!found) {
                int cur = v;
                while(cur != to) {
                    cycle.emplace_back(cur);
                    cur = p[cur];
                }
                cycle.emplace_back(cur);
            }
            found++;
        }
    }
    u[v] = 2;
}
void dfs2(int v) {
    u[v] = 1;
    for(int to: g[v]) {
        if(make_pair(v, to) == w) continue;
        if(u[to] == 0) {
            dfs2(to);
        } else if(u[to] == 1){
            found = 1;
        }
    }
    u[v] = 2;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
    }
    for(int i = 1; i <= n; i++) {
        if(!u[i]) {
            dfs(i, 0);
        }
    }
    if(cycle.size() == 0) {
        cout << "YES\n";
        return;
    }
    reverse(cycle.begin(), cycle.end());
    int len = cycle.size();
    for(int i = 0; i < len; i++) {
        int j = (i + len - 1) % len;
        w = make_pair(cycle[j], cycle[i]);
        for(int t = 1; t <= n; t++) u[t] = 0;
        found = 0;
        for(int i = 1; i <= n; i++) {
            if(!u[i]) dfs2(i);
        }
        if(!found) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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