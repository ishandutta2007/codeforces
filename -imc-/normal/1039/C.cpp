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

struct Graph {
    map<int, int> remap;
    vector<vector<int>> e;

    int getRemap(int x) {
        if (remap.count(x)) {
            return remap[x];
        } else {
            int sz = remap.size();
            remap[x] = sz;
            e.emplace_back();
            return sz;
        }
    }

    void connect(int u, int v) {
        u = getRemap(u);
        v = getRemap(v);

        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<char> used;

    void dfs(int v) {
        used[v] = true;
        for (int u : e[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    }

    int countDelta() {
        int nc = 0;

        used.assign(remap.size(), false);
        for (int i = 0; i < remap.size(); ++i) {
            if (!used[i]) {
                dfs(i);
                ++nc;
            }
        }

        return remap.size() - nc;
    }
};

const int MOD = 1e9 + 7;

void solve(bool __attribute__((unused)) read) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    map<int, Graph> graphs;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        int x = c[u] ^ c[v];
        graphs[x].connect(u, v);
    }

    vector<int> powers(max(n, k) + 1);
    powers[0] = 1;
    for (int i = 1; i < powers.size(); ++i) {
        powers[i] = powers[i - 1] * 2 % MOD;
    }

    int answer = 0;

    for (auto& it : graphs) {
        int p = n - it.second.countDelta();
        answer += powers[p];
        if (answer >= MOD) {
            answer -= MOD;
        }
    }

    int extra = powers[k] + MOD - graphs.size();
    extra %= MOD;
    answer += extra * powers[n] % MOD;
    answer %= MOD;

    cout << answer << endl;
}