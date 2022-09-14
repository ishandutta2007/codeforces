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
    int n;
    ll k;
    cin >> n >> k;
    --k;

    vector<ll> p(n + 1);
    p[0] = p[1] = 1;
    for (int i = 2; i <= n; ++i) {
        p[i] = min(p[i - 1] * 2, k + 1);
    }

    if (k >= p[n]) {
        cout << -1 << endl;
        return;
    }

    vector<int> res(n);
    iota(all(res), 1);

    int pos = 0;
    while (pos < n) {
        ll sum = 0;

        int to = pos + 1;
        for (; sum + p[n - to] <= k; ++to) {
            sum += p[n - to];
        }
        k -= sum;

        // cerr << pos << " " << to << endl;

        reverse(res.begin() + pos, res.begin() + to);
        pos = to;
    }

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}