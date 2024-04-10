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
    vector<string> s(3);
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }

    vector<int> delta(3);
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 2 * n; ++i) {
            delta[k] += s[k][i] == '0' ? -1 : 1;
        }
        delta[k] = delta[k] >= 0 ? 1 : -1;
    }   

    for (int a = 0; a < 3; ++a) {
        for (int b = a + 1; b < 3; ++b) {
            if (delta[a] == delta[b]) {
                if (delta[a] == -1) {
                    for (int k = 0; k < 3; ++k) {
                        for (int i = 0; i < 2 * n; ++i) {
                            s[k][i] = '0' + '1' - s[k][i];
                        }
                    }
                }
                string res;

                int i = 0, j = 0;

                while (i < 2 * n || j < 2 * n) {
                    int d = -1;
                    if ((i < 2 * n && s[a][i] == '0') || (j < 2 * n && s[b][j] == '0')) {
                        d = 0;
                    } else {
                        d = 1;
                    }

                    res += char('0' + d);

                    if (i < 2 * n && s[a][i] == char('0' + d)) {
                        ++i;
                    }
                    if (j < 2 * n && s[b][j] == char('0' + d)) {
                        ++j;
                    }
                }

                while (sz(res) < 3 * n) {
                    res += '0';
                }

                if (delta[a] == -1) {
                    for (int i = 0; i < 3 * n; ++i) {
                        res[i] =  '0' + '1' - res[i];
                    }
                }

                cout << res << endl;
                return;
            }
        }
    }
    assert(false);

}