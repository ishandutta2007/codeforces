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
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txst", "w", stdout); 
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = (n % 3 == 0 ? 1 : 0); i < n; i += 3) {

        for (int j = 0; j < m; ++j) {
            s[i][j] = 'X';
        }

        if (i + 2 >= n) {
            continue;
        }

        bool ok = false;
        for (int j = 0; j < m; ++j) {
            if (s[i + 1][j] == 'X' || s[i + 2][j] == 'X') {
                s[i + 1][j] = 'X';
                s[i + 2][j] = 'X';
                ok = true;
                break;
            }
        }
        if (!ok) {
            s[i + 1][0] = 'X';
            s[i + 2][0] = 'X';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i] << "\n"; 
    }
    


}