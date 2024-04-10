#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

bool deleted[N];
int w[N], sz[N];
vector<pair<int, int>> g[N];
double der[N];
int n;

int find_centroid(int u, int p, int all_sz) {
    int mx = 0;
    int id = 0;
    int sum = 1;
    for (auto e : g[u]) {
        if (e.first == p) continue;
        if (deleted[e.first]) continue;
        sum += sz[e.first];
        if (sz[e.first] > mx) {
            mx = sz[e.first];
            id = e.first;
        }
    }
    mx = max(mx, all_sz - sum);
    return (mx <= all_sz / 2 ? u : find_centroid(id, u, all_sz));
}

int dfs_sz(int u, int p) {
    sz[u] = 1;
    for (auto e : g[u]) {
        if (e.first == p) continue;
        if (deleted[e.first]) continue;
        sz[u] += dfs_sz(e.first, u);
    }
    return sz[u];
}

double dfs_der(int u, int p, int l) {
    der[u] = -3.0 / 2 * w[u] * sqrt(l);
    for (auto e : g[u]) {
        if (e.first == p) continue;
        der[u] += dfs_der(e.first, u, l + e.second);
    }
    return der[u];
}

double calc(int u, int p, int l) {
    double res = w[u] * pow(l, 1.5);
    for (auto e : g[u]) {
        if (e.first == p) continue;
        res += calc(e.first, u, l + e.second);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int root = 1;
    vector<int> candidates;
    while (true) {
        // cout << root << endl;
        // for (int i = 1; i <= n; i++) cout << deleted[i];
        // cout << endl;
        int sz = dfs_sz(root, 0);
        if (sz <= 2) {
            candidates.push_back(root);
            for (auto e : g[root]) {
                if (!deleted[e.first]) candidates.push_back(e.first); 
            }
            break;
        }
        int centroid = find_centroid(root, 0, sz);
        vector<pair<int, double>> ders;
        for (auto e : g[centroid]) {
            ders.push_back({e.first, dfs_der(e.first, centroid, e.second)});
        }
        double sum = 0;
        for (auto e : ders) {
            sum -= e.second;
        }
        bool has_decrease = false;
        for (auto e : ders) {
            if (sum + 2 * e.second < 0) {
                root = e.first;
                has_decrease = true;
            }
        }
        // cout << centroid << ' ' << root << endl;
        if (!has_decrease) {
            candidates.push_back(centroid);
            break;
        }
        for (auto e : g[centroid]) {
            if (e.first != root) {
                deleted[e.first] = 1;
            } 
        }
    }


    double mn = 1e25;
    int best = 0;
    for (auto e : candidates) {
        double foo = calc(e, 0, 0);
        if (foo < mn) {
            mn = foo;
            best = e;
        }
    }

    cout << best << ' ' << setprecision(10) << fixed << mn << endl;

    return 0;
}