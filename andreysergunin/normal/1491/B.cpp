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
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    bool eq = true;
    for (int i = 0; i < n; ++i) {
        eq &= a[0] == a[i];
    }

    if (eq) {
        cout << v + min(u, v) << endl;
        return;
    }

    bool blocked = true;
    for (int i = 0; i + 1 < n; ++i) {
        blocked &= abs(a[i] - a[i + 1]) <= 1;
    }


    cout << (blocked ? min(u, v) : 0) << endl;


}