#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; ++i)  {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (b[i][j] == 'X');
        }
    }

    vector<vector<int>> cur(n + 1, vector<int>(m + 1));
    vector<vector<int>> res(n + 1, vector<int>(m + 1));

    auto f = [&](int t) {
        for (int i = 0; i <= n; ++i) {
            cur[i].assign(m + 1, 0);
            res[i].assign(m + 1, 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i - t < 0 || i + t >= n || j - t < 0 || j + t >= m) {
                    continue;
                }
                int sum = pref[i + t + 1][j + t + 1];
                sum += pref[i - t][j - t];
                sum -= pref[i + t + 1][j - t];
                sum -= pref[i - t][j + t + 1];

                if (sum == (2 * t + 1) * (2 * t + 1)) {
                    cur[i + t + 1][j + t + 1] += 1;
                    cur[i + t + 1][j - t] += -1;
                    cur[i - t][j + t + 1] += -1;
                    cur[i - t][j - t] += 1;
                    res[i][j] = 1;
                }
            }
        }

        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= m; ++j) {
        //         cout << cur[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > 0) {
                    cur[i][j] += cur[i][j - 1];
                }
                if (i > 0) {
                    cur[i][j] += cur[i - 1][j];
                }
                if (i > 0 && j > 0) {
                    cur[i][j] -= cur[i - 1][j - 1];
                }
                if (b[i][j] == 'X') {
                    ok &= cur[i][j] > 0;
                }
            }
        }

        // cout << t << endl;
        // for (int i = 0; i < n; ++i) {
        //     string s;
        //     for (int j = 0; j < m; ++j) {
        //         if (cur[i][j] > 0) {
        //             s += 'X';
        //         } else {
        //             s += '.';
        //         }
        //     }

        //     cout << s << "\n";
        // }
        // cout << endl;

        return ok;
    };

    int lf = 0, rg = min(n, m) + 1;
    while (rg - lf > 1) {
        int t = (lf + rg) / 2;
        
        if (f(t)) {
            lf = t;
        } else {
            rg = t;
        }
    }

    assert(f(lf));
    cout << lf << "\n";

    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = 0; j < m; ++j) {
            if (res[i][j] > 0) {
                s += 'X';
            } else {
                s += '.';
            }
        }

        cout << s << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}