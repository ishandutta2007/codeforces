#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int x[maxn];
int y[maxn];
bool s[maxn];
int n;
int mod = 998244353;
int dp[maxn];
int f[maxn];

void add(int i, int x) {
    for (; i < maxn; i = (i | (i + 1))) {
        f[i] = (f[i] + x) % mod;
    }
}

int get(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        ans = (ans + f[r]) % mod;
    }
    return ans;
}

int get(int l, int r) {
    return (get(r) - (l ? get(l - 1) : 0) + mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
//    sort(a, a + n);
    dp[0] = (x[0] - y[0]) % mod;
    add(0, dp[0]);
    for (int i = 1; i < n; i++) {
        int e = lower_bound(x, x + n, y[i]) - x;
//        cout << e << " " << i << " " << get(e, i) << "\n";
        dp[i] = (x[i] - y[i] + get(e, i) + mod) % mod;
        add(i, dp[i]);
//        for (int i = 0; i < n; i++) {
//            cout << f[i] << " ";
//        }
//        cout << "\n";
    }
    int ans = (x[n - 1] + 1) % mod;
    for (int i = 0; i < n; i++) {
//        cout << dp[i] << "\n";
        if (s[i])
            ans = (ans + dp[i]) % mod;
    }
    cout << ans;
}