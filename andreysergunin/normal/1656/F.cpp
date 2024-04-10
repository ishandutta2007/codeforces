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

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const ll INF = 2e6;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }

    sort(all(a));

    ll lf = -INF, rg = INF;

    auto f = [&](ll t) {
        vector<ll> b = a;
        for (int i = 0; i < n; ++i) {
            b[i] += t;
        }
        ll res = - t * t * (n - 1);

        if (b[0] >= 0) {
            for (int i = 1; i < n; ++i) {
                res += b[i] * b[0];
            }
            return res;
        }
        if (b.back() <= 0) {
            for (int i = 0; i < n - 1; ++i) {
                res += b[i] * b.back();
            }
            return res;   
        }
        res -= b[0] * b.back();
        for (int i = 0; b[i] < 0; ++i) {
            res += b[i] * b.back();
        }
        for (int i = n - 1; b[i] > 0; --i) {
            res += b[i] * b[0];
        }
        return res;

    };

    while (rg - lf > 2) {
        ll m1 = (2 * lf + rg) / 3;
        ll m2 = (lf + 2 * rg) / 3;

        if (f(m1) < f(m2)) {
            lf = m1;
        } else {
            rg = m2;
        }
    }

    if (lf == -INF && f(lf - 1) > f(lf))  {
        cout << "INF\n";
        return;
    }
    if (rg == INF && f(rg + 1) > f(lf))  {
        cout << "INF\n";
        return;
    }


    cout << max({f(lf), f((lf + rg) / 2), f(rg)}) << '\n';
}