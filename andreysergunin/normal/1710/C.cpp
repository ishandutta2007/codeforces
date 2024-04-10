#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
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

const int P = 998244353;

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

void solve() {  
    string s;
    cin >> s;

    array<int, 8> dp, nxt;
    dp.fill(0); nxt.fill(0);
    dp[7] = 1;

    int val = 0;

    for (char c : s) {
        int d = c - '0';
        add(val, val + d);
        for (int mask = 0; mask < 8; ++mask) {
            for (int tr : {0, 2, 3, 4, 5, 7}) {
                bool ok = true;
                int nxt_mask = 0;
                for (int b = 0; b < 3; ++b) {
                    if (((tr & mask) & (1 << b)) && d == 0) {
                        ok = false;
                        break;
                    }
                    if (((mask >> b) & 1) &&  (d == ((tr >> b) & 1))) {
                        nxt_mask |= 1 << b;
                    }
                }
                if (ok) {
                    add(nxt[nxt_mask], dp[mask]);
                }
            }            
        }
        dp = nxt;
        nxt.fill(0);
    }

    int tmp = 0;
    for (int i = 0; i < 8; ++i) {
        add(tmp, dp[i]);
    }

    int res = val + 1;
    add(res, 3);
    mul(res, val + 1);
    sub(res, 1);
    mul(res, val + 1);
    for (int i = 0; i < 8; ++i) {
        int x = dp[i];
        mul(x, 3);
        sub(res, x);
    }

    cout << res << endl;
}