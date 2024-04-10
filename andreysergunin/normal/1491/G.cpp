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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }    

    vector<vector<int>> cycles;

    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        if (p[i] == i) {
            continue;
        }

        vector<int> cycle;
        for (int j = i; !used[j]; j = p[j]) {
            used[j] = 1;
            cycle.push_back(j);
        }
        reverse(all(cycle));
        cycles.push_back(cycle);
    }

    vector<pii> res;

    while (sz(cycles) > 1) {
        vector<int> a = cycles.back();
        cycles.pop_back();
        vector<int> b = cycles.back();
        cycles.pop_back();

        res.push_back({a[0], b[0]});
        for (int i = sz(a) - 1; i >= 1; --i) {
            res.push_back({b[0], a[i]});
        }
        for (int i = sz(b) - 1; i >= 1; --i) {
            res.push_back({a[0], b[i]});
        }
        res.push_back({a[0], b[0]});
    }

    if (sz(cycles) == 1) {
        vector<int> a = cycles.back();
        if (sz(a) > 2) {
            res.push_back({a[0], a[1]});
            res.push_back({a[0], a.back()});
            res.push_back({a[1], a.back()});
            for (int i = sz(a) - 2; i >= 1; --i) {
                res.push_back({a[0], a[i]});
            }
        } else {
            vector<int> used(n);
            for (int x : a) {
                used[x] = 1;
            }
            int dummy = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    dummy = i;
                    break;
                }
            }
            res.push_back({a[0], dummy});
            res.push_back({a[1], dummy});
            res.push_back({a[0], dummy});
        }
    }

    vector<int> cnt(n);
    for (auto [x, y] : res) {
        swap(p[x], p[y]);
        cnt[p[x]] ^= 1;
        cnt[p[y]] ^= 1;
    }

    // for (int i = 0; i < n; ++i) {
    //     cerr << p[i] << " ";
    // }
    // cerr << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << cnt[i] << " ";
    // }
    // cerr << endl;

    assert(sz(res) <= n + 1);

    cout << sz(res) << "\n";
    for (auto [x, y] : res) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}