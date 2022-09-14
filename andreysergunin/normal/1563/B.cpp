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

const int MAXN = 4000400;

int mod;

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int &a, int b) {
     a -= b;
     if (a < 0) {
        a += mod;
     }
}

int suff[MAXN];


void solve() {  
    int n;
    cin >> n >> mod;
    suff[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        int res = suff[i + 1];
        for (int k = 2; k * i <= n; ++k) {
            int cur = suff[k * i];
            sub(cur, suff[min(n + 1, k * (i + 1))]);
            add(res, cur);
        }
        suff[i] = suff[i + 1];
        add(suff[i], res);
    }

    int res = suff[1];
    sub(res, suff[2]);
    cout << res << endl;
}