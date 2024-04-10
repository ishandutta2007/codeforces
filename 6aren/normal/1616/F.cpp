#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> id_edges(n, vector<int>(n, -1));
    vector<vector<int>> val_edges(n, vector<int>(n, -1));

    vector<vector<int>> basises(m);
    vector<bool> has(m);
    
    auto add_to_basises = [&](vector<int> vec) {
        while (true) {
            int id = -1;
            for (int i = 0; i < m; i++) {
                if (vec[i] != 0) {
                    id = i;
                    break;
                }
            }
            if (id == -1 && vec.back() != 0) {
                return false;
            }
            if (id == -1) break;
            if (!has[id]) {
                basises[id] = vec;
                has[id] = true;
                break;
            } else {
                int u = basises[id][id];
                int v = vec[id];
                for (int i = id; i <= m; i++) {
                    vec[i] = vec[i] * u - basises[id][i] * v;
                    while (vec[i] >= 3) vec[i] -= 3;
                    while (vec[i] < 0) vec[i] += 3;
                }
            }
        }
        return true;
    };
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        id_edges[a][b] = i;
        val_edges[a][b] = c;
        id_edges[b][a] = i;
        val_edges[b][a] = c;
        if (c != -1) {
            vector<int> foo(m + 1);
            foo[i] = 1;
            foo[m] = c % 3;
            if (!add_to_basises(foo)) {
                ok = false;
            }
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (id_edges[i][j] != -1 && id_edges[j][k] != -1 && id_edges[k][i] != -1) {
                    vector<int> foo(m + 1, 0);
                    foo[id_edges[i][j]] = 1;
                    foo[id_edges[i][k]] = 1;
                    foo[id_edges[j][k]] = 1;
                    if (!add_to_basises(foo)) {
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!has[i]) {
            vector<int> foo(m + 1);
            foo[i] = 1;
            if (!add_to_basises(foo)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    int inv[3] = {0, 1, 2};
    vector<int> res(m);
    for (int i = m - 1; i >= 0; i--) {
        int cur = basises[i][m];
        for (int j = m - 1; j > i; j--) {
            cur -= basises[i][j] * res[j];
            while (cur < 0) cur += 3;
        }
        res[i] = cur * inv[basises[i][i]];
        res[i] %= 3;
    }

    for (int e : res) cout << (e == 0 ? 3 : e) << ' ';
    cout << '\n';

    return 0;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    } 
}