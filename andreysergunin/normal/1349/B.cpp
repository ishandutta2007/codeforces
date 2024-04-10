#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == k) {
            ++cnt;
        }        
    }
    if (cnt == 0) {
        cout << "no\n";
        return;
    }

    if (n == 1) {
        cout << "yes\n";
        return;
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] >= k && a[i + 1] >= k) {
            cout << "yes\n";
            return;
        }
    }

    for (int i = 0; i + 2 < n; ++i) {
        if (a[i] >= k && a[i + 2] >= k) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
}