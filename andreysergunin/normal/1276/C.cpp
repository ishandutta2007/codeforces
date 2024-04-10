#pragma GCC optimize("Ofast", "unroll-loops")
 
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
 
    while (tests--) {
        solve();
    }
 
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// -----------------------------------------------------------------------

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    vector<pii> p;

    int cnt = 1, cur = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] == cur) {
            ++cnt;
        } else {
            p.push_back({cnt, cur});
            cnt = 1;
            cur = a[i];
        }
    }
    p.push_back({cnt, cur});

    sort(all(p));

    int opt = 0;
    int opt_x = 0, opt_y = 0;

    for (int x = 1; x * x <= n; ++x) {
        int sum = 0;

        for (int i = 0; i < sz(p); ++i) {
            sum += min(p[i].first, x);
        }

        if (sum < x * x) {
            continue;
        }

        if (opt < x * (sum / x)) {
            opt = x * (sum / x);
            opt_x = x;
            opt_y = sum / x;
        }
    }

    cout << opt << endl;
    cout << opt_x << " " << opt_y << endl;

    int x = opt_x, y = opt_y;

    vector<vector<int>> res(x, vector<int>(y));

    int s = 0, t = 0;

    auto nxt = [&]() {
        ++t;
        if (t == x) {
            t = 0;
            ++s;
        }
    };

    for (int i = sz(p) - 1; i >= 0; --i) {

        for (int j = 0; j < min(p[i].first, x); ++j) {
            res[t][(s + t) % y] = p[i].second;
            nxt();

            if (s == y) {
                break;
            }
        }

        if (s == y) {
            break;
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }





}