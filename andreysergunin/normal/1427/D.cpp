#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
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
    cout << setprecision(6) << fixed;
    cerr << setprecision(6) << fixed;

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

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<vector<int>> res;

    auto f = [&](const vector<int> &s) {
        vector<vector<int>> arr;
        int i = 0;
        for (auto x : s) {
            arr.push_back({});
            for (int j = 0; j < x; ++j, ++i) {
                arr.back().push_back(a[i]);
            }
        }
        reverse(all(arr));
        i = 0;
        for (auto v : arr) {
            for (auto x : v) {
                a[i++] = x;
            }
        }
    };

    while (true) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= a[i] == i;
        }
        if (ok) {
            break;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }

        for (int i = 0; i + 1 < n; ++i) {
            if (b[i] > b[i + 1]) {
                int pos = b[i + 1];
                while (a[pos + 1] == a[pos] + 1) {
                    ++pos;
                }
                res.push_back({b[i + 1], pos - b[i + 1] + 1, b[i] - pos, n - b[i] - 1});
                f(res.back());
                break;
            }
        }
    }

    cout << sz(res) << "\n";

    for (auto v : res) {
        int cnt = 0;
        for (int x : v) {
            cnt += x > 0;
        }
        cout << cnt << " ";
        for (int x : v) {
            if (x > 0) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }

}