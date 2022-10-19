#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int n;
int ans[N];
vector<int> g[N];
set<ii> s[N];
int mx[N], c[N];
int id[N];
int final_ans[N];

void dfs(int u, int p) {
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u);
        if (s[id[u]].size() < s[id[e]].size()) swap(id[e], id[u]);
        for (ii ee : s[id[e]]) {
            auto it = s[id[u]].lower_bound({ee.x, 0});
            if (it == s[id[u]].end() || it->x != ee.x) {
                s[id[u]].insert({ee.x, ee.y});
                if (mx[id[u]] < ee.y) {
                    mx[id[u]] = ee.y;
                    ans[id[u]] = ee.x;
                } else if (mx[id[u]] == ee.y) {
                    ans[id[u]] += ee.x;
                }
            } else {
                s[id[u]].insert({ee.x, ee.y + it->y});
                s[id[u]].erase(it);
                if (mx[id[u]] < ee.y + it->y) {
                    mx[id[u]] = ee.y + it->y;
                    ans[id[u]] = it->x;
                } else if (mx[id[u]] == ee.y + it->y) {
                    ans[id[u]] += it->x;
                }
            }
        }
    }
    final_ans[u] = ans[id[u]];
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        s[i].insert({c[i], 1});
        id[i] = i;
        mx[i] = 1;
        ans[i] = c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << final_ans[i] << ' ';
    return 0;
}