#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
ll st[maxn];
ll a[maxn];
vector<int> d[maxn];
int u[maxn];
int v[maxn];
ll binpow(ll x, int y) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
void solve() {
    cin >> n >> k;
    for(int i=0; i <= k; i++) {
        st[i] = binpow(i, n);
    }
    for(int i = 1; i <= k; i++) {
        u[i] = 1;
        v[i] = i;
    }
    for(int i = 2; i <= k; i++) {
        if(v[i] == i) {
            for(int j = i; j <= k; j+=i) {
                v[j]/=i;
                if(v[j] % i == 0) u[j] = 0;
                u[j] *= -1;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        a[i] = (a[i] + a[i - 1]) % mod;
        for(int j = i; j <= k; j+=i) {
            a[j] = (a[j] - st[(j-1)/i] * u[i] + st[j/i] * u[i]) % mod;
            if(a[j] < 0) a[j] += mod;
        }
        ans = (ans + (a[i] ^ i)) % mod;
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