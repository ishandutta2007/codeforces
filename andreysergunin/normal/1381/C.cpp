#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }
    int r = -1;
    for (int i = 0; i <= n; ++i) {
        if (cnt[i] == 0) {
            r = i;
            break;
        }
    }
    vector<vector<int>> to(n + 1);

    set<pii> setik;

    for (int i = 0; i <= n; ++i) {
        if (cnt[i] > 0) {
            setik.insert({cnt[i], i});
        }
    }


    for (int i = 0; i < x; ++i) {
        auto it = setik.end();
        --it;
        auto [c, k] = *it;
        setik.erase(it);
        --cnt[k];
        to[k].push_back(k);
        if (c > 1) {
            setik.insert({c - 1, k});
        }
    }


    if (!setik.empty()) {
        
        int shift = (--setik.end())->first;
        if (2 * shift > n - x + n - y) {
            cout << "NO\n";
            return;
        }

        vector<int> arr;
        while (!setik.empty()) {
            auto it = --setik.end();
            auto [c, k] = *it;
            setik.erase(it);
            for (int i = 0; i < c; ++i) {
                arr.push_back(k);
            }
        }

        int cur = x;
        for (int i = 0; i < sz(arr); ++i) {
            int j = (i + shift) % sz(arr);
            if (cur == y || arr[i] == arr[j]) {
                to[arr[i]].push_back(r);
            } else {
                to[arr[i]].push_back(arr[j]);
                ++cur;
            }
        }


    }

    cout << "YES\n";

    for (int i = 0; i < n; ++i) {
        assert(!to[a[i]].empty());
        cout << to[a[i]].back() + 1 << " ";
        to[a[i]].pop_back();
    }
    cout << "\n";


}