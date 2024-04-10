#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)2e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n;
ll x, y;
int dp[maxn];
int d[maxn];
int L;
ll rec(ll x, ll y) {
    if(x == y) return 0;
    if(y % L != 0 || y - x <= 5 * L) {
        ll z = y - 1;
        for(int i = 2; i <= n; i++) {
            if(y  - y % i >= x) z = min(z, y - y % i);
        }
        return rec(x, z) + 1;
    }
    ll cur = x/L*L + 2 * L;
    ll dif = (y-cur)/L;
    return rec(x,y-dif*L) + d[L] * dif;
}
void solve(){
    cin >> y >> x >> n;
    L = 1;
    for(int i = 2; i <= n; i++) {
        L = L * i/__gcd(i, L);
    }
    for(int i = 1; i <= 4 * L; i++) {
        dp[i] = i - 1;
        for(int j = 2; j <= n; j++) {
            dp[i] = min(dp[i], i - i % j);
        }
        d[i] = d[dp[i]] + 1;
    }
    for(int i = L + 1; i <= 4 * L; i++) {
        int c = i % L;
        if(c == 0) c = L;
        int cur = d[c] + d[i - c];
        if(d[i] != cur) {
            cout << "bad\n";
        }
    }
    cout << rec(x, y) << "\n";

}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}