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

//#define int li

void solve(bool __attribute__((unused)) read) {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto bfs = [&](int color) {
        vector<int> d(n, -1);
        deque<int> q;

        for (int i = 0; i < n; ++i) {
            if (a[i] == color) {
                d[i] = 0;
                q.push_back(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();

            for (int u: e[v]) {
                if (d[u] != -1) continue;

                d[u] = d[v] + 1;
                q.push_back(u);
            }
        }

        return d;
    };

    vector<vector<int>> dists(k);
    for (int i = 0; i < k; ++i) {
        dists[i] = bfs(i);
    }

    vector<li> ans(n);

    vector<int> x(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j)
            x[j] = dists[j][i];
        nth_element(x.begin(), x.begin() + s - 1, x.end());

        for (int t = 0; t < s; ++t)
            ans[i] += x[t];
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}