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
    freopen("input.txt", "r", stdin);
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

    vector<int> a(n);

    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        if (2 * cnt[i] - 1 > n) {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> both(n), one(n);
    int prv = a[0];
    int res = 1;

    for (int i = 0; i < n - 1; ++i)  {
        if (a[i] == a[i + 1]) {
            ++res;
            if (prv == a[i]) {
                ++both[a[i]];
            } else {
                ++one[a[i]];
                ++one[prv];
            }
            prv = a[i + 1];
        }
    }
    if (prv == a[n - 1]) {
        ++both[a[n - 1]];
    } else {
        ++one[a[n - 1]];
        ++one[prv];
    }

    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (2 * both[i] - 1 + one[i] > res) {
            assert(k == -1);
            k = i;
            res = 2 * both[i] - 1 + one[i];
        }
    }
    cout << res - 1 << endl;

}