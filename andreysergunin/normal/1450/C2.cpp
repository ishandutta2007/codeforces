#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(8) << fixed;
    cerr << setprecision(8) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> cnt(3, vector<int>(2));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'X') {
                ++cnt[(i - j + 3 * n) % 3][0];
            }
            if (s[i][j] == 'O') {
                ++cnt[(i - j + 3 * n) % 3][1];
            }
        }
    }

    int u = 0, v = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                continue;
            }
            if (cnt[u][0] + cnt[v][1] > cnt[i][0] + cnt[j][1]) {
                u = i;
                v = j;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'X' && (i - j + 3 * n) % 3 == u) {
                s[i][j] = 'O';
            }
            if (s[i][j] == 'O' && (i - j + 3 * n) % 3 == v) {
                s[i][j] = 'X';
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        cout << s[i] << "\n";
    }
}