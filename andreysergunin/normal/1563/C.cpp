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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    if (n % 2 == 0) {
        if (a[n - 1] != n - 1) {
            cout << "-1" << endl;
            return;
        }
        --n;
    }

    vector<int> res;
    auto f = [&](int k) {
        reverse(a.begin(), a.begin() + k);
        res.push_back(k);
    };

    for (int i = 0; i < n; ++i) {
        if ((a[i] ^ i) & 1) {
            cout << "-1" << endl;
            return;
        }
    }

    while (n > 1) { 
        for (int i = 0; i < n; ++i) {
            if (a[i] == n - 1) {
                f(i + 1);
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == n - 2) {
                f(i);
                f(i + 2);                
                break;
            }
        }
        f(3);
        f(n);
        n -= 2;
    }

    cout << sz(res) << endl;
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;


    for (int i = 0; i < sz(a); ++i) {
        assert(a[i] == i);
    }
}