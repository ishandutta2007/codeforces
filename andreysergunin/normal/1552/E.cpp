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
    // cin >> tests;

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
    vector<int> a(n * k);
    vector<vector<int>> arr(n);
    for (int i = 0; i < n * k; ++i) {
        cin >> a[i];
        --a[i];
        arr[a[i]].push_back(i);
    }
    int l = (n + k - 2) / (k - 1);

    vector<pii> res(n, {-1, -1});
    vector<int> used(n);

    for (int pos = 1; pos < k; ++pos) {
        vector<pii> p;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                p.push_back({arr[i][pos], i});
            }
        }
        sort(all(p));
        for (int j = 0; j < min(sz(p), l); ++j) {
            int i = p[j].second;
            used[i] = true;
            res[i] = {arr[i][pos - 1], arr[i][pos]};
        }
    }

    for (auto [x, y] : res) {
        cout << x + 1 << " " << y + 1 << endl;
    }

}