#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int mod = 1e9 + 7;

int pw(int a, int b) {
    if(!b) return 1;
    if(b & 1) return ll(a) * pw(a, b - 1) % mod;
    a = pw(a, b >> 1);
    return ll(a) * a % mod;
}

int fac[2001];

int cnk(int a, int b) {
    return ll(fac[a]) * pw(ll(fac[b]) * fac[a - b] % mod, mod - 2) % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    fac[0] = 1;
    for(int i = 1; i <= 2000; i++) fac[i] = ll(fac[i - 1]) * i % mod;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;

    int k = 0, m = 0;
    for(int i = 0; i < n; i++) k += (a[i] == -2);
    vector<bool> ok(n, true);
    for(int i = 0; i < n; i++) if(a[i] != -2) ok[i] = ok[a[i]] = false;
    for(int i = 0; i < n; i++) m += ok[i];

    int ans = 0;
    for(int i = 0; i <= m; i++) if(i & 1) {
        ans = (ans - ll(cnk(m, i)) * fac[k - i] % mod + mod) % mod;
    } else {
        ans = (ans + ll(cnk(m, i)) * fac[k - i]) % mod;
    }
    cout << ans;
}