#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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

const int MAXN = 40;
const int MAXM = 16;

int dp[MAXN][1 << MAXM];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int rnk = 0;

    for (int b = m - 1; b >= 0; --b) {
        int k = -1;
        for (int i = rnk; i < n; ++i) {
            if (a[i] & (1ll << b)) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            continue;
        }
        swap(a[rnk], a[k]);

        for (int i = rnk + 1; i < n; ++i) {
            if (a[i] & (1ll << b)) {
                a[i] ^= a[rnk];
            }
        }
        ++rnk;
    }   

    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    vector<int> used(m, -1);
    for (int i = rnk - 1; i >= 0; --i) {
        int b = -1;;
        for (int j = 0; j < m; ++j) {
            if (a[i] & (1ll << j)) {
                b = j;
            }
        }
        assert(b != -1);
        used[b] = i;

        for (int j = 0; j < i; ++j) {
            if (a[j] & (1ll << b)) {
                a[j] ^= a[i];
            }
        }
    }

    int k = 0;
    vector<int> to(m, -1);

    for (int i = 0; i < m; ++i) {
        if (used[i] == -1) {
            to[i] = k++;
        }
    }

    vector<ll> c(rnk);
    for (int i = 0; i < rnk; ++i) {
        for (int j = 0; j < m; ++j) {
            if (to[j] != -1 && (a[i] & (1ll << j))) {
                c[i] |= 1ll << to[j];
            }
        }
    }

    // for (int i = 0; i < rnk; ++i) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;

    int p = 1;
    for (int i = 0; i < n - rnk; ++i) {
        mul(p, 2);
    }

    vector<int> res(m + 1);

    if (rnk <= 20) {
        for (int mask = 0; mask < (1 << rnk); ++mask) {
            ll x = 0;
            for (int i = 0; i < rnk; ++i) {
                if (mask & (1 << i)) {
                    x ^= a[i];
                }   
            }
            ++res[__builtin_popcountll(x)];
        }
    } else {
        dp[0][0] = 1;

        for (int i = 0; i < rnk; ++i) {
            for (int j = rnk; j >= 0; --j) {
                for (int mask = 0; mask < (1 << (m - rnk)); ++mask) {
                    add(dp[j + 1][mask ^ c[i]], dp[j][mask]);
                }
            }
        }

        for (int j = 0; j <= rnk; ++j) {
            for (int mask = 0; mask < (1 << (m - rnk)); ++mask) {
                add(res[j + __builtin_popcountll(mask)], dp[j][mask]);
            }
        }
    }

    for (int i = 0; i <= m; ++i) {
        mul(res[i], p);
    }

    for (int i = 0; i <= m; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;



}