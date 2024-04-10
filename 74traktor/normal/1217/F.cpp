#include <bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, k = 800;
unordered_set < int > g[maxn];
multiset < int > G[maxn];
int cur, numb;
int used[maxn];
int ok, what;
int number[maxn];

void dfs(int v) {
    used[v] = cur;
    number[v] = numb;
    for (auto u : g[v]) if (used[u] != cur) dfs(u);
}

void dfs1(int v) {
    used[v] = cur;
    if (v == what) ok = 1;
    for (auto u : G[v]) if (used[u] != cur) dfs1(u);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, last = 0, t, x, y;
    cin >> n >> m;
    vector < pair < int, int > > operation;
    vector < int > type;
    for (int i = 1; i <= m; ++i) {
        cin >> t >> x >> y;
        if (x > y) swap(x, y);
        operation.push_back({x, y});
        type.push_back(t);
        if (i % k == 0 || i == m) {
            vector < pair < int, int > > add_edge;
            for (int j = 1; j <= n; ++j) G[j] = {};
            for (int j = 0; j < (int)type.size(); ++j) {
                if (type[j] == 1) {
                    pair < int, int > T = operation[j];
                    for (int lst = 0; lst <= 1; ++lst) {
                        x = (T.first + lst - 1) % n + 1, y = (T.second + lst - 1) % n + 1;
                        if (g[x].find(y) != g[x].end()) {
                            g[x].erase(y);
                            g[y].erase(x);
                            add_edge.push_back({x, y});
                        }
                    }
                }
            }
            numb = 0, cur++;
            for (int j = 1; j <= n; ++j) {
                if (used[j] != cur) {
                    numb++;
                    dfs(j);
                }
            }
            for (auto key : add_edge) {
                g[key.first].insert(key.second), g[key.second].insert(key.first);
                if (number[key.first] != number[key.second]) G[number[key.first]].insert(number[key.second]), G[number[key.second]].insert(number[key.first]);
            }
            for (int j = 0; j < (int)type.size(); ++j) {
                x = (operation[j].first + last - 1) % n + 1, y = (operation[j].second + last - 1) % n + 1;
                if (type[j] == 1) {
                    if (g[x].find(y) == g[x].end()) {
                        if (number[x] != number[y]) {
                            G[number[x]].insert(number[y]);
                            G[number[y]].insert(number[x]);
                        }
                        g[x].insert(y);
                        g[y].insert(x);
                    }
                    else {
                        g[x].erase(y);
                        g[y].erase(x);
                        if (number[x] != number[y]) {
                            G[number[x]].erase(G[number[x]].find(number[y]));
                            G[number[y]].erase(G[number[y]].find(number[x]));
                        }
                    }
                }
                else {
                    cur++;
                    what = number[y], ok = 0;
                    dfs1(number[x]);
                    last = ok;
                    cout << last;
                }
            }
            type = {};
            operation = {};
            /*for (int j = 1; j <= n; ++j) {
                cout << j << "  :  ";
                for (auto key : g[j]) cout << key << " ";
                cout << '\n';
            }
            cout << '\n';*/
        }
    }
    return 0;
}