#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r2", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    ll res = 0;
    for (int i = 1; i + 1 < n; ++i) {
        res += (a[i] + 1) / 2;
    }
    bool small = true;
    int zero = 0, odd = 0;
    for (int i = 1; i + 1 < n; ++i) {
        small &= a[i] <= 1;
        zero += a[i] == 0;
        odd += (a[i] & 1);
    }

    if (small && zero != n - 2) {
        cout << -1 << "\n";
        return;
    }

    if (odd == 1 && zero == n - 3) {
        cout << -1 << "\n";
        return;
    }
 
    cout << res << "\n";
}