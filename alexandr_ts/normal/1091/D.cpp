#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 2e15 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 10;

ll fac[N], bfac[N];

ll pw(ll x, int n) {
    if (n == 0)
        return 1;
    if (n % 2)
        return pw(x, n - 1) * x % MOD;
    ll t = pw(x, n / 2);
    return t * t % MOD;
}

void prec() {
    fac[0] = 1;
    frab(i, 1, N)
        fac[i] = fac[i - 1] * i % MOD;
    fr(i, N)
        bfac[i] = pw(fac[i], MOD - 2);
}

void solve() {
    ll n;
    cin >> n;
    prec();
    ll ans = 0;
    frab(len, 0, n - 1)
        ans = (ans + fac[n] * bfac[n - len] % MOD * (n - len - 1) % MOD * len) % MOD;
    ans = (ans + fac[n]) % MOD;
    cout << ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();
}