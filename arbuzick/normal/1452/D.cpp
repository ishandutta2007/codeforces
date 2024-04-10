#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int mod = 998244353;
pair<int, int> sum(pair<int, int> f, pair<int, int> s) {
    pair<int, int> r;
    r.s = f.s*s.s%mod;
    r.f = f.f*s.s%mod+s.f*f.s%mod;
    r.f %= mod;
    int a = r.f, b = r.s;
    while (b > 0)
        a %= b, swap(a, b);
    r.f /= a;
    r.s /= a;
    return r;
}
pair<int, int> mul(pair<int, int> f, pair<int, int> s) {
    pair<int, int> r;
    r.f = f.f*s.f;
    r.s = s.s*f.s;
    int a = r.f, b = r.s;
    while (b > 0)
        a %= b, swap(a, b);
    r.f /= a;
    r.s /= a;
    return r;
}
int binpow(int n, int k) {
    if (k == 0)
        return 1;
    if (k%2 == 1)
        return binpow(n, k-1)*n%mod;
    int a = binpow(n, k/2);
    return a*a%mod;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n += 2;
    vector<pair<int, int>> dp(n);
    pair<int, int> x2 = {1, 2}, x1 = {0, 1};
    for (int i = 1; i+1 < n; ++i) {
        if (i%2 == 0) {
            dp[i].f = x1.f;
            dp[i].s = x1.s;
            x1 = mul(x1, {1, 4});
            x2 = sum(x2, mul(dp[i], {1, 2}));
        } else {
            dp[i].f = x2.f;
            dp[i].s = x2.s;
            x2 = mul(x2, {1, 4});
            x1 = sum(x1, mul(dp[i], {1, 2}));
        }
    }
    int ans = dp[n-2].f*binpow(dp[n-2].s, mod-2)%mod;
    cout << ans;
    return 0;
}