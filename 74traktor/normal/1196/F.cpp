#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 100005;
vector < pair < int, int > > g[maxn];
int dist[maxn];
int inf = 1e18;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector < pair < int, pair < int, int > > > T;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        T.push_back({w, {u, v}});
    }
    sort(T.begin(), T.end());
    set < int > used;
    for (int i = 0; i < min(m, k); ++i) used.insert(T[i].second.first), used.insert(T[i].second.second);
    vector < int > isi;
    for (auto key : used) isi.push_back(key);
    for (int i = 0; i < min(m, k); ++i) {
        u = T[i].second.first, v = T[i].second.second;
        u = lower_bound(isi.begin(), isi.end(), u) - isi.begin() + 1, v = lower_bound(isi.begin(), isi.end(), v) - isi.begin() + 1;
        g[u].push_back({v, T[i].first});
        g[v].push_back({u, T[i].first});
    }
    vector < int > cur;
    for (int i = 1; i <= (int)isi.size(); ++i) {
        for (int j = 1; j <= (int)isi.size(); ++j) dist[j] = inf;
        dist[i] = 0;
        set < pair < int, int > > Q;
        for (int j = 1; j <= (int)isi.size(); ++j) {
            Q.insert({dist[j], j});
        }
        for (int j = 1; j <= (int)isi.size(); ++j) {
            auto p = (*Q.begin());
            if (p.first == inf) break;
            if (p.first != 0) cur.push_back(p.first);
            Q.erase(Q.begin());
            for (auto u : g[p.second]) {
                if (p.first + u.second < dist[u.first]) {
                    Q.erase({dist[u.first], u.first});
                    dist[u.first] = p.first + u.second;
                    Q.insert({dist[u.first], u.first});
                }
            }
        }
    }
    sort(cur.begin(), cur.end());
    cout << cur[2 * k - 1] << '\n';
    return 0;
}