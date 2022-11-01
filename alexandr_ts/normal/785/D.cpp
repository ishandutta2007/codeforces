#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;
const ll MOD = 10000*100000 + 7;
const ll INF = 2e9 + 10;
const int MAX = 1010;

ll f[N], f1[N];

ll powMod(ll x, ll pw) {
    if (pw == 0) return 1;
    ll tmp = powMod(x, pw / 2);
    if (pw % 2)
        return (x * tmp) % MOD * tmp % MOD;
    return tmp * tmp % MOD;
}

ll cnk(ll n, ll k) {
    return (f[n] * f1[k] % MOD) * f1[n - k] % MOD;
}

ll pref[N], suf[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    f[0] = 1;
    f[1] = 1;
    frab(i, 2, N)
        f[i] = (f[i - 1] * i) % MOD;
    frab(i, 0, N)
        f1[i] = powMod(f[i], MOD - 2);

    string s;
    cin >> s;
    int n = s.size();
    fr(i, n)
        pref[i] = (i ? pref[i - 1] : 0) + (s[i] == '(');
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + (s[i] == ')');

    ll ans = 0;
    fr(i, n)
        if (s[i] == '(' && suf[i])
            ans = (ans + cnk(pref[i] - 1 + suf[i], suf[i] - 1)) % MOD;
    cout << ans;
}