#include<bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 5;
vector < int > g[maxn], G[maxn];
int t[maxn], ans[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        G[t[i]].push_back(i);
    }
    vector < int > answ;
    set < int > Q;
    for (int i = 1; i <= n; ++i) Q.insert(i);
    for (int i = 1; i <= n; ++i) {
        for (auto key : G[i]) {
            vector < int > add;
            for (auto elem : g[key]) {
                if (Q.find(ans[elem]) != Q.end()) {
                    Q.erase(ans[elem]);
                    add.push_back(ans[elem]);
                }
            }
            if ((*Q.begin()) != t[key]) {
                cout << -1;
                exit(0);
            }
            for (auto key : add) Q.insert(key);
            answ.push_back(key);
            ans[key] = i;
        }
    }
    for (auto key : answ) cout << key << " ";
    cout << '\n';
    return 0;
}