#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2 * n, vector<int> (n));
    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            v[i][j]--;
        }
    // 0 - free
    // 1 - taken
    // 2 - banned
    vector<int> state(2 * n);
    int ans = 1;
    for (int q = 0; q < n; ++q) {
        int must_take = -1;
        for (int i = 0; i < n; ++i) {
            vector<int> f(n, -1);
            for (int j = 0; j < 2 * n; ++j) {
                if (state[j] != 0)
                    continue;
                if (f[v[j][i]] == -1)
                    f[v[j][i]] = j;
                else
                    f[v[j][i]] = -2;
            }
            for (int j = 0; j < n; ++j)
                if (f[j] >= 0)
                    must_take = f[j];
            if (must_take != -1)
                break;
        }
        // cout << must_take << endl;
        if (must_take == -1) {
            ans = (ans * 2) % mod;
            for (int i = 0; i < 2 * n; ++i)
                if (state[i] == 0) {
                    must_take = i;
                    break;
                }
        }
        state[must_take] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 2 * n; ++j)
                if (state[j] == 0 && v[j][i] == v[must_take][i])
                    state[j] = 2;
    }
    cout << ans << "\n";
    for (int i = 0; i < 2 * n; ++i)
        if (state[i] == 1)
            cout << i + 1 << ' ';
    cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
	return 0;
}