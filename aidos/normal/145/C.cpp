#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
map<int, int> id;
int cnt[maxn];
int sz;
int bad = 0;
void get(int x) {
    int y = x;
    while(y > 0) {
        if(y % 10 == 4 || y % 10 == 7) {
            y /= 10;
        } else {
            bad++;
            return;
        }
    }
    if(id.count(x) == 0) {
        id[x] = ++sz;
    }
    cnt[id[x]]++;
}
int dp[2020][2020];
ll fact[maxn];
int get(int pos, int val) {
    if(val < 0) return 0;
    if(pos == 0) {
        if(val == 0) return 1;
        return 0;
    }
    int &res = dp[pos][val];
    if(res != -1) return res;
    res = (get(pos - 1, val) + get(pos - 1, val - 1) * 1ll * cnt[pos]) % mod;
    return res;
}
ll binpow(ll x, ll y) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y/=2;
    }
    return res;
}
ll C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * 1ll * binpow(fact[k] * fact[n-k] % mod, mod-2) % mod;
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        get(a[i]);
    }
    memset(dp, -1, sizeof dp);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    ll ans = 0;
    for(int i = 0; i <= sz; i++) {
        ans = (ans + get(sz, i) * C(bad, k-i)) % mod;
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}