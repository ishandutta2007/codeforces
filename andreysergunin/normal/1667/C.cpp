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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
    // cout << setprecision(10) << fixed;
    // cerr << setprecision(10) << fixed;

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

void solve() {  
    int n;
    cin >> n;
    int k = n / 3;
    if (n % 3 == 0) {
        cout << 2 * k << endl;
        --k;
        for (int i = 0; i <= k; ++i) {
            cout << i + 1 << " " << k - i + 1 << endl;
        }
        for (int i = 0; i < k; ++i) {
            cout << i + k + 2 << " " << 2 * k - i + 1 << endl;
        }
        cout << n << " " << n << endl;
        return;
    }

    cout << 2 * k + 1 << endl;

    for (int i = 0; i <= k; ++i) {
        cout << i + 1 << " " << k - i + 1 << endl;
    }
    for (int i = 0; i < k; ++i) {
        cout << i + k + 2 << " " << 2 * k - i + 1 << endl;
    }

}