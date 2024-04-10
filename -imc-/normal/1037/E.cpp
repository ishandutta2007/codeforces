#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

#define int li

void solve(bool);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

    //while (true) solve(false);

    return 0;
}

vector<set<int>> e;
vector<int> deg;
set<pair<int, int>> degs;
vector<char> inSet;

void solve(bool __attribute__((unused)) read) {
    int n, m, k;
    cin >> n >> m >> k;

    e.clear();
    e.resize(n);
    deg.assign(n, 0);
    degs.clear();

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        e[u].insert(v);
        e[v].insert(u);
        ++deg[u];
        ++deg[v];
        edges.emplace_back(u, v);
    }

    for (int v = 0; v < n; ++v) {
        degs.insert(make_pair(deg[v], v));
    }

    inSet.assign(n, true);
    int answer = n;

    auto relax = [&]() {
        while (!degs.empty() && degs.begin()->first < k) {
            int v = degs.begin()->second;
            degs.erase(degs.begin());
            inSet[v] = false;
            --answer;

            for (int u : e[v]) {
                if (inSet[u]) {
                    degs.erase(make_pair(deg[u], u));
                    --deg[u];
                    degs.insert(make_pair(deg[u], u));
                }
            }
        }
    };

    auto delEdge = [&](int a, int b) {
        e[a].erase(b);
        e[b].erase(a);

        if (inSet[a] && inSet[b]) {
            for (int u : { a, b }) {
                degs.erase(make_pair(deg[u], u));
                --deg[u];
                degs.insert(make_pair(deg[u], u));
            }
        }
        relax();
    };

    relax();
    vector<int> answers;
    for (int i = edges.size() - 1; i >= 0; --i) {
        answers.push_back(answer);
        delEdge(edges[i].first, edges[i].second);
    }
    reverse(all(answers));

    for (int x : answers) {
        cout << x << "\n";
    }
}