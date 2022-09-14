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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int cnt = s[0][0] == '*';
    int x = 0, y = 0;
    while (true) {
        int optx = -1, opty = -1;
        for (int i = x; i < n; ++i) {
            for (int j = y; j < m; ++j) {
                if (i == x && j == y) {
                    continue;
                }
                if (s[i][j] == '*') {
                    if ((optx == -1 && opty == -1) || abs(x - optx) + abs(y - opty) > abs(x - i) + abs(y - j)) {
                        optx = i;
                        opty = j;
                    }
                }
            }
        }
        if (optx == -1 && opty == -1) {
            break;
        }
        ++cnt;
        x = optx; y = opty;
    }
    cout << cnt << endl;
}