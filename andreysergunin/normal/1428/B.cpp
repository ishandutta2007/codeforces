#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
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
    cerr << setprecision(5) << fixed;

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
    string s;
    cin >> s;

    bool lf = true, rg = true;
    for (int i = 0; i < n; ++i) {
        lf &= (s[i] != '>');
        rg &= (s[i] != '<');
    }
    if (lf || rg) {
        cout << n << "\n";
        return;
    }

    vector<int> a = {0};
    for (int i = 0; i < n; ++i) {
        if (s[i] == '-') {
            ++a.back();
        } else {
            a.push_back(0);
        }
    }

    a[0] += a.back();
    a.pop_back();
    ll res = 0;
    for (int x : a) {
        if (x >= 1) {
            res += x + 1;
        }
    }

    cout << res << endl;
}