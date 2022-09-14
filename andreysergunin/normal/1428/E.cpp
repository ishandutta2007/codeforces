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
    cout << setprecision(8) << fixed;
    cerr << setprecision(5) << fixed;

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

void solve() {    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (ll &x : a) {
        cin >> x;
    }

    auto sqr = [](ll x) {
        return x * x;
    };

    auto f = [&](ll a, ll b) {
        return sqr((a + b - 1) / b) * (a % b) + sqr(a / b) * (b - (a % b));
    };

    vector<int> cnt(n, 1);
    set<pair<ll, int>> setik;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] * a[i];
        if (cnt[i] != a[i]) {
            setik.insert({f(a[i], cnt[i]) - f(a[i], cnt[i] + 1), i});
        }
    }

    for (int op = 0; op < k - n; ++op) {
        assert(!setik.empty());
        auto it = --setik.end();
        auto [delta, i] = *it;
        // cerr << delta << " " << i << endl;
        setik.erase(it);
        res -= delta;
        ++cnt[i];
        if (cnt[i] != a[i]) {
            setik.insert({f(a[i], cnt[i]) - f(a[i], cnt[i] + 1), i});
        }
    }

    cout << res << endl;


    

    // for (int n = 2; n <= 10000; ++n) {
    //     vector<ll> arr;

    //     for (int i = 1; i <= n; ++i) {
    //         arr.push_back(f(n, i));
    //     }

    //     vector<ll> delta;

    //     for (int i = 0; i + 1 < sz(arr); ++i) {
    //         delta.push_back(arr[i] - arr[i + 1]);
    //     }

    //     // for (ll x : delta) {
    //     //     cerr << x << " ";
    //     // }
    //     // cerr << endl;

    //     for (int i = 0; i + 1 < sz(delta); ++i) {
    //         assert(delta[i] >= delta[i + 1]);
    //     }
    // }

    

       


}