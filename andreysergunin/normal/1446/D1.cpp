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
    // freopen("input.txt", "r", stdin);
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }

    pii maxx = {-1, -1};

    for (int i = 0; i < n; ++i) {
        maxx = max(maxx, {cnt[i], i});
    }
    int k = maxx.second;

    int res = 0;
    for (int c = 0; c < min(111, n); ++c) {
        if (c == k) {
            continue;
        }

        vector<int> pos;
        vector<int> col;

        for (int i = 0; i < n; ++i) {
            if (a[i] == c || a[i] == k) {
                pos.push_back(i);
                col.push_back(a[i]);
            }
        }

        int s = sz(pos);
        vector<int> d(2 * s + 1, -1);

        int delta = 0;
        d[s + delta] = 0;

        for (int i = 0; i < sz(pos); ++i) {
            delta += col[i] == k ? 1 : -1;

            if (d[s + delta] != -1) {
                int lf = d[s + delta];
                int rg = (i + 1 == sz(pos) ? n : pos[i + 1]);
                res = max(res, rg - lf);
            } else {
                d[s + delta] = pos[i] + 1;
            }
        }
    }

    cout << res << endl;

}