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

const int P = 31607;

void mul(int &a, int b) {
    a = a * b % P;
}

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
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
    return binPow(a, P - 2);
}

const int MAXN = 21;
int a[MAXN][MAXN];
int prod[MAXN][1 << MAXN];

void solve() {      
    int n;
    cin >> n;

    int r = inv(10000);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            // a[i][j] = rnd() % 9999 + 1;
            mul(a[i][j], r);
        }
    }

    for (int i = 0; i < n; ++i) {
        prod[i][0] = 1;
        int b = -1;
        for (int mask = 1; mask < (1 << n); ++mask) {
            if ((mask & (mask - 1)) == 0) {
                ++b;
            }
            prod[i][mask] = prod[i][mask ^ (1 << b)];
            mul(prod[i][mask], a[i][b]);
        }
    }

    int res = 1;

    for (int mask = 0; mask < (1 << (n + 2)); ++mask) {
        int d0 = (mask >> n) & 1;
        int d1 = (mask >> (n + 1)) & 1;

        int cur = 1;
        for (int i = 0; i < n; ++i) {
            int msk0 = (~mask) & ((1 << n) - 1);
            int msk1 = (mask) & ((1 << n) - 1);

            if (d0 && (msk0 & (1 << i))) {
                msk0 ^= (1 << i);
                msk1 ^= (1 << i);
            }

            if (d1 && (msk0 & (1 << (n - 1 - i)))) {
                msk0 ^= (1 << (n - 1 - i));
                msk1 ^= (1 << (n - 1 - i));
            }

            mul(cur, prod[i][msk1]);
            mul(cur, P + 1 - prod[i][msk0]);
        }

        // cout << bitset<4>(mask) << " " << cur << endl;

        if (__builtin_popcount(mask) & 1) {
            add(res, cur);
        } else {
            sub(res, cur);
        }
    }

    cout << res << endl;

}