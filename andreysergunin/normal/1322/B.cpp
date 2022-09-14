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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pii> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {0, i};
    }

    vector<pii> t[2];

    int res = 0;

    ll cnt = 0;
    for (int k = 0; k < 28; ++k) {
        ll u = 0, v = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & (1 << k)) {
                ++u;
            } else {
                ++v;
            }
        }
        int x = (u * v + cnt) & 1;

        if (x) {
            res ^= (1 << k);
        }

        for (int i = 0; i < n; ++i) {
            int j = b[i].second;
            if (a[j] & (1 << k)) {
                b[i].first ^= (1 << k);
                t[1].push_back(b[i]);
            } else {
                t[0].push_back(b[i]);
            }
        }

        for (int i = 0; i < sz(t[0]); ++i) {
            b[i] = t[0][i];
        }
        for (int i = 0; i < sz(t[1]); ++i) {
            b[sz(t[0]) + i] = t[1][i];
        }

        t[0].clear();
        t[1].clear();

        // for (int i = 0; i < n; ++i) {
        //     cerr << b[i].first << " ";
        // }
        // cerr << endl;
        
        cnt = 0;
        int ptr = n;
        for (int i = 0; i < n; ++i) {
            while (ptr > 0 && b[ptr - 1].first + b[i].first >= (1 << (k + 1))) {
                --ptr;
            }
            cnt += n - ptr;
            if (2 * b[i].first >= (1 << (k + 1))) {
                --cnt;
            }
        }
        // cerr << cnt << endl;
        cnt /= 2;
        // cerr << cnt << endl;
    }

    cout << res << endl;
}