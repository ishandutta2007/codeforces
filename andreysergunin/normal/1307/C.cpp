// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 26;
ll f[MAXN];
ll g[MAXN][MAXN];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; ++j) {
            g[j][c] += f[j];
        }
        ++f[c];
    }

    ll res = 0;
    for (int i = 0; i < 26; ++i) {
        res = max(res, f[i]);
        for (int j = 0; j < 26; ++j) {
            res = max(res, g[i][j]);
        }
    }
    cout << res << endl;
}