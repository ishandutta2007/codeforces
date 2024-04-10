#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e15 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 2e6 + 5;

ll f[N], f1[N]; // factorials and factorials ^ (MOD - 2).

ll powMod(ll x, ll pw) { // power
    if (pw == 0) return 1;
    ll tmp = powMod(x, pw / 2);
    if (pw % 2)
        return (x * tmp) % MOD * tmp % MOD;
    return tmp * tmp % MOD;
}

ll cnk(ll n, ll k) {
    return (f[n] * f1[k] % MOD) * f1[n - k] % MOD;
}

void precalc() {
    f[0] = 1;
    f[1] = 1;
    frab(i, 2, N)
        f[i] = (f[i - 1] * i) % MOD;
    frab(i, 0, N)
        f1[i] = powMod(f[i], MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    precalc();
    ll n;
    cin >> n;
    n++;
    cout << cnk(2 * n, n) - 1;
}