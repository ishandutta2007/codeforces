#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

const int N = 5010;
int n;
int a[N];
int dp[N][N];
int cnt_less[N];

int f[N];

void build() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
    }
}

int pref_sum[N];

void build_level(int cnt) {
    for (int pref = 0; pref < n; ++pref) {
        pref_sum[pref] = mul(dp[pref][cnt], max(0, cnt_less[pref] - cnt + 1));
        if (pref > 0) {
            pref_sum[pref] = add(pref_sum[pref], pref_sum[pref - 1]);
        }
    }
}

int get_pref(int l, int r) {
    chkmin(r, n - 1);
    chkmax(l, 0);
    if (r < l) return 0;
    return sub(pref_sum[r], l > 0 ? pref_sum[l - 1] : 0);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cnt_less[i] = 0;
        for (int j = 0; j < i; ++j) {
            cnt_less[i] += (int)(a[i] > a[j]);
        }
    }
    // cerr << "cnt_less = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << cnt_less[i] << " ";
    // }
    // cerr << endl;
    for (int pref = 0; pref < n; ++pref) {
        dp[pref][2] = cnt_less[pref];
    }
    build_level(2);
    for (int cnt = 4; cnt <= n; cnt += 2) {
        for (int pref = 0; pref < n; ++pref) {
            dp[pref][cnt] = get_pref(0, cnt_less[pref] - 1);
            // for (int last_pref = 0; last_pref < cnt_less[pref]; ++last_pref) {
            //     dp[pref][cnt] = add(dp[pref][cnt], pref_sum[last_pref]);
            // }
        }
        build_level(cnt);
    }
    // cout << "dp =" << endl;
    // for (int pref = 0; pref < n; ++pref) {
    //     for (int cnt = 2; cnt <= n; cnt += 2) {
    //         cout << dp[pref][cnt] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = dp[n - 1][n];
    for (int l = 0; l < n;) {
        int r = l;
        while (r < n && a[l] == a[r]) {
            ++r;
        }
        ans = mul(ans, inv(f[r - l]));
        l = r;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}