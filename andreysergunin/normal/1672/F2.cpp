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
 
int task;
 
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
    vector<int> a(n), b(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {   
        cin >> a[i];
        ++cnt[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];

    }

    vector<int> arr = a;
    sort(all(arr));
    arr.resize(unique(all(arr)) - arr.begin());

    int biggest = 0;
    for (int i = 0; i < sz(arr); ++i) {
        if (cnt[arr[i]] > cnt[arr[biggest]]) {
            biggest = i;
        }
    }

    vector<vector<int>> g(sz(arr));

    for (int i = 0; i < n; ++i) {
        g[lower_bound(all(arr), a[i]) - arr.begin()].push_back(lower_bound(all(arr), b[i]) - arr.begin());
    } 

    vector<int> color(sz(arr));
    function<bool(int)> dfs = [&](int v) {
        if (v == biggest) {
            return false;
        }
        color[v] = 1;
        for (int u : g[v]) {
            if (color[u] == 0) {
                if (dfs(u)) {
                    return true;
                }
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    };

    bool ok = true;
    for (int i = 0; i < sz(arr); ++i) {
        if (!color[i]) {
            ok &= !dfs(i);
        }
    }

    cout << (ok ? "AC\n" : "WA\n");
}