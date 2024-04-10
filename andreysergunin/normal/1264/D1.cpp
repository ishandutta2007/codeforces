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

const int P = 998244353;


void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
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

int rev(int a) {
    return binPow(a, P - 2);
}

const int MAXN = 2020;

int pref[MAXN][MAXN];
int suff[MAXN][MAXN];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    pref[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= i; ++k) {
            if (s[i] != ')') {
                add(pref[i + 1][k + 1], pref[i][k]);
            }
            if (s[i] != '(') {
                add(pref[i + 1][k], pref[i][k]);
            }
        }
    }

    suff[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int k = 0; k <= n - 1 - i; ++k) {
            if (s[i] != '(') {
                add(suff[i][k + 1], suff[i + 1][k]);
            }
            if (s[i] != ')') {
                add(suff[i][k], suff[i + 1][k]);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            add(suff[i][j], suff[i][j + 1]);
        }
    }

    int res = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                continue;
            }
            int cur = pref[i][k - 1];
            mul(cur, suff[i + 1][k]);
            add(res, cur);
        }
    }

    cout << res << endl;
}
 
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