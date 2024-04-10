//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;

int n, m;
vector<pair<int, int>> g[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, x; cin >> u >> v >> x; u--; v--;
        g[u].push_back({v, x}); g[v].push_back({u, x});
    }
    vector<pair<int, int>> d(n, {INF, INF});
    d[0] = {0, 0};
    set<pair<pair<int, int>, int>> q;
    q.insert({{0, 0}, 0});
    vector<int> p(n, -1);
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(pair<int, int> e : g[v]) {
            int to = e.first, x = e.second;
            if(make_pair(d[v].first + 1, d[v].second + !x) < d[to]) {
                q.erase({d[to], to});
                d[to] = {d[v].first + 1, d[v].second + !x};
                q.insert({d[to], to});
                p[to] = v;
            }
        }
    }
    vector<int> path;
    int v = n - 1;
    while(v != -1) {
        path.push_back(v);
        v = p[v];
    }
    reverse(all(path));
    set<pair<int, int>> inp;
    for(int i = 1; i < sz(path); i++) {
        inp.insert({path[i - 1], path[i]});
        inp.insert({path[i], path[i - 1]});
    }
    vector<int> x, y, z;
    for(int u = 0; u < n; u++)
        for(pair<int, int> e : g[u]) {
            int v = e.first;
            if(u > v) continue;
            if(e.second && inp.find({u, v}) == inp.end()) {
                x.push_back(u);
                y.push_back(v);
                z.push_back(0);
            } else if(!e.second && inp.find({u, v}) != inp.end()) {
                x.push_back(u);
                y.push_back(v);
                z.push_back(1);
            }
        }
    cout << sz(x) << '\n';
    for(int i = 0; i < sz(x); i++) {
        cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << z[i] << '\n';
    }
}