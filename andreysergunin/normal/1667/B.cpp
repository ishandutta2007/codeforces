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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
    // cout << setprecision(10) << fixed;
    // cerr << setprecision(10) << fixed;

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

const int INF = 1e9;

struct BIT {    
    BIT() = default;
    BIT(int n) {
        arr.assign(n, -INF);
    }

    void update(int i, int val) {
        for (; i < sz(arr); i |= (i + 1)) {
            arr[i] = max(arr[i], val);
        }
    }

    int get(int i) {
        int res = -INF;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            res = max(res, arr[i]);
        }
        return res;
    }

    vector<int> arr;
};

void solve() {  
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    auto arr = pref;
    sort(all(arr));
    arr.resize(unique(all(arr)) - arr.begin());

    vector<int> dp(n + 1);
    dp[0] = 0;
    BIT bit(n);
    bit.update(lower_bound(all(arr), pref[0]) - arr.begin(), 0);

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + (a[i] < 0 ? -1 : a[i] > 0);
        int pos = lower_bound(all(arr), pref[i + 1]) - arr.begin();
        int s = bit.get(pos - 1);
        if (s != -INF) {
            dp[i + 1] = max(dp[i + 1], s + i + 1);
        }
        bit.update(pos, dp[i + 1] - (i + 1));
    }

    cout << dp[n] << endl;
}