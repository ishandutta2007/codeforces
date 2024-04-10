#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
int n, k;
long long fact[maxn];
long long rfact[maxn];
long long binpow(long long x, long long y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return binpow(x, y-1) * x % mod;
    return binpow(x*x % mod, y/2);
}
long long C(int n, int k) {
    if(n < k) return 0;
    return fact[n] * rfact[k] % mod * rfact[n-k]  % mod;
}
void solve() {
    cin >> n >> k;
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    rfact[maxn - 1] = binpow(fact[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--) {
        rfact[i] = rfact[i+1] * (i + 1) % mod;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + C(n/i-1, k-1)) % mod;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}