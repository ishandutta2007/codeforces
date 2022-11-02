#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
ll f[maxn], t, l, r;
void solve(){
    cin >> t >> l >> r;
    for(ll i = 1; i <= r; i++) {
        f[i] = i * (i - 1)/2;
    }
    for(ll i = 2; i <= r; i++) {
        for(ll j = 2; j*i<=r; j++) {
            f[j * i] = min(f[j * i], f[i] + i * j * (j - 1)/2);
        }
    }
    ll ans = 0, st = 1;
    for(int i = l; i <= r; i++) {
        ans = (ans + f[i] % mod * st) % mod;
        st = st * t % mod;
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