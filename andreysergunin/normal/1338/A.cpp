#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) { 
        cin >> a[i];
    }

    ll k = 0;

    for (int t = 0; ; ++t) {

        ll cur = a[n - 1] + k;
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            if (cur < a[i]) {
                ok = false;
                break;
            }
            cur = min(cur, a[i] + k);
        }

        if (ok) {
            cout << t << "\n";
            break;
        }
        k = 2 * k + 1;
    }
}