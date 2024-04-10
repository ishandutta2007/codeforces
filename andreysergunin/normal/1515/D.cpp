#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

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
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";s
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(l), b(r);
    map<int, int> mapa;
    for (int &x : a) {
        cin >> x;
        ++mapa[x];
    }
    for (int &x : b) {
        cin >> x;
        --mapa[x];
    }

    int ch = abs(r - l) / 2;

    int x = 0;
    int rem = 0;
    for (auto [col, cnt] : mapa) {
        rem += abs(cnt);
        if (cnt < 0 && l < r) {
            x += abs(cnt) / 2;
        } else if (cnt > 0 && l > r) {
            x += abs(cnt) / 2;
        }
    }
    rem /= 2;

    int res = rem + ch - min(ch, x);
    cout << res << endl;


}