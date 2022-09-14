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
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    auto better = [&](const vector<int> &a, const vector<int> &b) {
        int cnt = 0;
        for (int i = 0; i < 5; ++i) {
            cnt += a[i] < b[i];
        }
        return cnt >= 3;
    };

    int cand = 0;
    for (int i = 1; i < n; ++i) {
        if (better(a[i], a[cand])) {
            cand = i;
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (i != cand) {
            ok &= better(a[cand], a[i]);
        }
    }
    cout << (ok ? cand + 1 : -1) << endl;
}