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

void solve() {  
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    int res = 0;

    vector<pii> cur;
    cur.emplace_back(a[n - 1], 1);

    for (int i = n - 2; i >= 0; --i) {
        int x = a[i];
        vector<pii> nxt;
        for (auto [y, cnt] : cur)  {
            int ops = (x + y - 1) / y;
            nxt.emplace_back(x / ops, cnt);
            --ops;
            mul(ops, i + 1);
            mul(ops, cnt);
            add(res, ops);
        }
        nxt.emplace_back(x, 1);
        int k = 1;
        for (int j = 1; j < sz(nxt); ++j) {
            if (nxt[k - 1].first == nxt[j].first) {
                add(nxt[k - 1].second, nxt[j].second);
            } else {
                nxt[k++] = nxt[j];
            }
        }
        nxt.resize(k);
        cur = nxt;
    }
    cout << res << endl;
}