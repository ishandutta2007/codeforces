#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
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
    cout << setprecision(15) << fixed;
    cerr << setprecision(15) << fixed;

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

void solve() { 
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n), b(k);
    for (int &x : p) {
        cin >> x;
        --x;
    }    
    for (int i = 0; i < n; ++i) {
        q[p[i]] = i; 
    }
    for (int &x : b) {
        cin >> x;
        --x;
    }

    vector<int> id(n, -1);
    for (int i = 0; i < k; ++i) {
        id[b[i]] = i;
    }

    
    vector<int> nxt(n), prv(n);

    for (int i = 0; i < n; ++i) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }

    int res = 1;
    for (int i = 0; i < k; ++i) {
        int pos = q[b[i]];

        int val = (prv[pos] != -1 && id[p[prv[pos]]] < i) + (nxt[pos] != n && id[p[nxt[pos]]] < i);
        // cerr << val << endl;
        res = res * val % 998244353;

        if (prv[pos] != -1) {
            nxt[prv[pos]] = nxt[pos];
        }
        if (nxt[pos] != n) {
            prv[nxt[pos]] = prv[pos];
        }
    }

    cout << res << endl;

}