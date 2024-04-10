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

int p;

void add(int &a, int b) {
    a += b;
    if (a >= p) {
        a -= p;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % p;
}

int binPow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

int inv(int a) {
    return binPow(a, p - 2);
}

void solve() {  
    int n, m;
    cin >> n >> m >> p;
    int k = n - m + 1;

    vector<int> fact(n + 1), rfact(n + 1);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = inv(fact[i]);
    }

    auto choose = [&](int n, int k) {
        int res = fact[n];
        mul(res, rfact[k]);
        mul(res, rfact[n - k]);
        return res;
    };

    auto f = [&](int n, int m) {
        if (m == 0) {
            return 1;
        }
        int k = n - m + 1;
        int res = binPow(2 * n + 2, m - 1);
        mul(res, 2);
        mul(res, k);
        return res;
    };

    int res = 0;
    for (int t = 0; t < m; ++t) {
        int x = binPow(2 * n + 2, m - t - 1);

        for (int d = 1; d <= t; ++d) {
            int cur = choose(t, d);

            mul(cur, f(d, d));
            mul(cur, f(n + 1 - (d + 2), t - d));

            mul(cur, x);
            mul(cur, d * (d + 1));

            mul(cur, k);

            add(res, cur);
        }
    }

    cout << res << endl;
}