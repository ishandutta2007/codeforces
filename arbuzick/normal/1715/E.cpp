#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

struct line {
    long long k, b;

    line() {
        k = b = 0;
    };

    line(long long _k, long long _b) {
        k = _k, b = _b;
    };

    long long operator()(int x) {
        return k * x + b;
    }
};

struct CHT {
    vector<line> cht;
    vector<long double> points;

    long double intersect(line a, line b) {
        return (a.b - b.b) / (long double)(b.k - a.k);
    }

    void add_line(line l) {
        while (cht.size() > 1 && intersect(l, cht.rbegin()[1]) <= points.back()) {
            points.pop_back();
            cht.pop_back();
        }
        if (!cht.empty()) {
            points.push_back(intersect(cht.back(), l));
        }
        cht.push_back(l);
    }

    CHT(vector<line> lines) {
        sort(lines.begin(), lines.end(), [&](line a, line b) {
            return a.k > b.k;
        });
        for (auto l : lines) {
            add_line(l);
        }
    }

    long long get(long long x) {
        return cht[lower_bound(points.begin(), points.end(), x) - points.begin()](x);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<long long> dist(n, inf);
    dist[0] = 0;
    for (int t = 0; t <= k; ++t) {
        set<pair<long long, int>> s;
        for (int i = 0; i < n; ++i) {
            s.insert({dist[i], i});
        }
        while (!s.empty() && s.begin()->first < inf) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (auto [u, w] : g[v]) {
                if (dist[u] > dist[v] + w) {
                    s.erase({dist[u], u});
                    dist[u] = dist[v] + w;
                    s.insert({dist[u], u});
                }
            }
        }
        if (t != k) {
            vector<line> lines;
            for (int i = 0; i < n; ++i) {
                if (dist[i] != inf) {
                    lines.emplace_back(-2 * i, dist[i] + i * 1LL * i);
                }
            }
            CHT cht(lines);
            for (int i = 0; i < n; ++i) {
                dist[i] = cht.get(i) + i * 1LL * i;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}