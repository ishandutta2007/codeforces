#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
ll fact[maxn];
int a[maxn];
int p[maxn];
ll rfact[maxn];
ll binpow(ll x, ll y) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
ll C(int n, int k) {
    return fact[n] * rfact[n-k] % mod * rfact[k] % mod;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    rfact[maxn-1] = binpow(fact[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--) {
        rfact[i]  = rfact[i + 1] * (i + 1) % mod;
    }

    ll ans = 1;
    for(ll i = 2; i * i <= inf; i++) {
        if(p[i] == 0) {
            for(ll j = i * 2; j * j <= inf; j += i) {
                p[j] = 1;
            }
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] % i == 0) {
                    while(a[j] % i == 0) {
                        a[j]/=i;
                        ++cnt;
                    }
                }
            }
            ans = (ans * C(cnt + n - 1, n - 1)) % mod;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != 1) {
            int cnt=1;
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j]) {
                    a[j] = 1;
                    cnt++;
                }
            }
            ans = (ans * C(cnt + n - 1, n - 1)) % mod;
        }
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