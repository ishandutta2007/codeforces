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
    int s = 0, s2 = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        s2 += a[i] * a[i];
    }   
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        s += b[i];
        s2 += b[i] * b[i];
    }

    vector<int> used(100 * n + 1);
    used[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i * 100; j >= 0; --j) {
            used[j + a[i]] |= used[j];
            used[j + b[i]] |= used[j];
            used[j] = 0;
        }
    }

    int res = s * s;
    for (int j = 0; j < sz(used); ++j) {
        if (used[j]) {
            res = min(res, j * j + (s - j) * (s - j));
        }
    }
    res += (n - 2) * s2;
    cout << res << endl;
}