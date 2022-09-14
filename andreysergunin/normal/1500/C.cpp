#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 1515;

void solve() {  
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            // a[i][j] = rnd() & 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    int col = -1;
    auto cmp = [&](const vector<int> &x, const vector<int> &y) {
        return x[col] < y[col];
    };

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    vector<bitset<MAXN>> u(m), v(m);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i + 1 < n; ++i) {
            if (b[i][j] != b[i + 1][j]) {
                u[j][i] = 1;
            }
            if (b[i][j] > b[i + 1][j]) {
                v[j][i] = 1;
            }
        }
    }

    bitset<MAXN> cur;

    vector<int> used(m);
    vector<int> ops;
    for (int t = 0; t < m; ++t) {
        for (int j = 0; j < m; ++j) {
            if (used[j]) {
                continue;
            }
            if ((cur & v[j]) == v[j]) {
                ops.push_back(j);
                cur |= u[j];
                used[j] = true;
                break;
            }
        }
    }

    reverse(all(ops));
    for (int j : ops) {
        col = j;
        stable_sort(all(a), cmp);
    }

    if (a == b) {
        cout << sz(ops) << "\n";
        for (int j : ops) {
            cout << j + 1 << " ";
        } 
        cout << "\n";
    } else {
        cout << "-1\n";
    }



}