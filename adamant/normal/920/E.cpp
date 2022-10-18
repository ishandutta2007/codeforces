#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 42;
int par[maxn], sz[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

void uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    par[a] = b;
    sz[b] += sz[a];
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b) {
        return g[a].size() < g[b].size();
    });
    for(int i = 0; i < n; i++) {
        if(i > 0 && 2 * g[p[i]].size() < n) {
            uni(p[i], p[i - 1]);
        } else {
            sort(begin(g[p[i]]), end(g[p[i]]));
            for(int j = 0; j < n; j++) {
                if(!binary_search(begin(g[p[i]]), end(g[p[i]]), j)) {
                    uni(p[i], j);
                }
            }
        }
    }
    set<int> pars;
    for(int i = 0; i < n; i++) {
        pars.insert(get(i));
    }
    multiset<int> ans;
    for(auto it: pars) {
        ans.insert(sz[it]);
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}