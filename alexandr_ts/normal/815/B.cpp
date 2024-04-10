#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;
const int N = 2e6 + 10;

ll a[N];

ll facts[N], obr[N];

ll powMod(ll n, ll p) {
    if (p == 0) return 1;
    ll tmp = powMod(n, p / 2);
    if (p % 2)
        return tmp * tmp % MOD * n % MOD;
    else
        return tmp * tmp % MOD;
}

ll cnk(int n, int k) {
    return facts[n] * obr[k] % MOD * obr[n - k] % MOD;
}

ll b[N];

int main() {
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    facts[0] = 1;
    frab(i, 1, N)
        facts[i] = facts[i - 1] * i % MOD;
    fr(i, N)
        obr[i] = powMod(facts[i], MOD - 2);

    ll sg = 1;
    fr(i, (n - 1) % 4) {
        fr(j, n - 1 - i)
            b[j] = a[j] + sg * a[j + 1], sg *= -1;
        fr(j, n - i)
            a[j] = b[j];
    }

    int n1 = n;
    n -= (n - 1) % 4;

    ll ans = 0;
    for (int i = 0; i < n; i += 2)
        ans = (ans + a[i] * cnk((n - 1) / 2, i / 2)) % MOD;
//    if (n1 % 4 == 3 || n1 % 4 == 2)
//        ans = -ans;
    ans = ((ans % MOD) + MOD) % MOD;
    cout << ans;
}