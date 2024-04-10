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

const int P = 1e9 + 7;

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    const int m = 60;
    vector<int> pw(2 * m);
    pw[0] = 1;
    for (int i = 1; i < sz(pw); ++i) {
        pw[i] = pw[i - 1];
        add(pw[i], pw[i - 1]);
    }

    vector<array<int, 2>> cnt(m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++cnt[j][(x[i] >> j) & 1];
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int p = 0;
        for (int a = 0; a < m; ++a) {
            if ((x[i] >> a) & 1) {
                int cur = cnt[a][1]; 
                mul(cur, pw[a]);
                add(p, cur);
            }
        }

        int q = 0;
        for (int b = 0; b < m; ++b) {
            int cur = pw[b]; 
            if ((x[i] >> b) & 1) {
                mul(cur, cnt[b][0] + cnt[b][1]);
            } else {
                mul(cur, cnt[b][1]);
            }   
            add(q, cur);
        } 

        mul(p, q);
        add(res, p);
    }

    cout << res << "\n";

    
}