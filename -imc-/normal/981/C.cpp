#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

bool isp(string s) {
    string x = s;
    reverse(all(x));
    return x == s;
}

vector<int> deg;
vector<vector<int>> e;
vector<vector<int>> paths;

void dfs(int v, int p) {
    bool one = true;
    for (int u: e[v]) {
        if (u == p) continue;

        if (p != -1 && !one) {
            cout << "No\n";
            exit(0);
        }

        if (p == -1) {
            paths.emplace_back();
        }

        paths.back().push_back(u);

        dfs(u, v);
        one = false;
    }
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;

    deg.resize(n);
    e.resize(n);

    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        ++deg[u];
        ++deg[v];

        e[u].push_back(v);
        e[v].push_back(u);
    }

    int root = max_element(all(deg)) - deg.begin();
    //cout << "chosen root " << root << endl;

    dfs(root, -1);
    cout << "Yes\n";
    cout << paths.size() << "\n";
    for (auto& it: paths) {
        assert(!it.empty());
        cout << root + 1 << " " << it.back() + 1 << "\n";
    }
}