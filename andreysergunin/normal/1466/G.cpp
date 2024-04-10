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

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

// vector<int> prefix(const string &s) {
//     int n = sz(s);
//     vector<int> p(n);
//     int k = 0;
//     for (int i = 0; i < n; ++i) {
//         while (k > 0 && s[k] != s[i]) {
//             k = p[k - 1];
//         }
//         if (s[k] == s[i]) {
//             ++k;
//         }
//         p[i] = k;
//     }
//     return p;
// }   

void solve() {  
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1];
        mul(pw[i], 2);
    }
    vector<int> rev(n + 1);
    rev[0] = 1;
    for (int i = 1; i <= n; ++i) {
        rev[i] = rev[i - 1];
        mul(rev[i], (P + 1) / 2);
    }

    vector<vector<int>> sum(n + 1, vector<int>(26));
    vector<vector<int>> cnt(n + 1, vector<int>(26));

    for (int i = 0; i < n; ++i) {
        cnt[i + 1] = cnt[i];
        ++cnt[i + 1][t[i] - 'a'];
        sum[i + 1] = sum[i];
        add(sum[i + 1][t[i] - 'a'], pw[n - i - 1]);
    }

    auto f = [&](string u, int k) {
        if (sz(u) == 0) {
            return pw[k];
        }
        int m = sz(u);
        int r = 0;
        int rem = m;
        int i = 0;
        for (; rem > 1 && i <= k; ++i) {
            vector<int> good(2, true);
            for (int x : {0, 1}) {
                for (int j = r + (x << i); j < sz(u); j += (1 << (i + 1))) {
                    good[x] &= u[j] == t[i];
                }
            }
            // cerr << good[0] << " " << good[1] << endl;
            if (!good[0] && !good[1]) {
                return 0;
            } else if (good[0] && !good[1]) {
                r += 1 << i;
                rem = rem / 2;
            } else if (good[1] && !good[0]) {
                rem = (rem + 1) / 2;
            } else {
                break;
            }
        }
        if (i == k + 1) {
            return 0;
        }

        // cerr << "! " << i << " " << r << " " << rem << " " << u << endl;

        int res = 0;
        int c = u[r] - 'a';
        for (int j = r, lf = 0; j < sz(u); j += (1 << i), ++lf) {
            int rg = rem - lf - 1;

            int p = 0;
            while (max(lf, rg) >= (1 << p)) {
                ++p;
            }
            // cerr << j << " " << p << endl;
            if (p + i > k || cnt[i + p][c] - cnt[i][c] != p) {
                continue;
            }
            int x = sum[k][c];
            sub(x, sum[i + p][c]);

            mul(x, rev[n - k]);
            // sub(x, cnt[k][c]);
            // add(x, cnt[i + p][c]);
            add(res, x);
        }

        return res;
    };

    for (int query = 0; query < q; ++query) {   
        int k;
        string w;
        cin >> k >> w;

        int res = 0;

        for (int j = 0; j <= sz(s); ++j) {
            bool ok = true;
            string u;

            for (int i = 0, l = j; i < sz(w); ++i, l = (l == sz(s) ? 0 : l + 1)) {
                if (l == sz(s)) {
                    u += w[i];
                }
                if (l != sz(s) && s[l] != w[i]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                continue;
            }

            add(res, f(u, k));
        }

        cout << res << "\n";
    }

    
}