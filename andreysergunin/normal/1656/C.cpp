#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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

    while (tests--) {
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

    bool one = false, zero = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        one |= a[i] == 1;
        zero |= a[i] == 0;
    }
    sort(all(a));

    if (!zero) {
        bool ok = true;
        for (int i = 0; i + 1 < n; ++i) {
            ok &= a[i] + 1 != a[i + 1];
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    if (one) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}