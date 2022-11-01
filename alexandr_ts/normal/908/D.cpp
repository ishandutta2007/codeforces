#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e3 + 10;

ll pw(ll x, ll p) {
    if (p == 0) return 1;
    if (p % 2) return (x * pw(x, p - 1)) % MOD;
    ll ans = pw(x, p / 2);
    return ans * ans % MOD;
}

ll d[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    int k, pa, pb;
    cin >> k >> pa >> pb;
    ll p1 = pw(pa + pb, MOD - 2);
    ll pb1 = pw(pb, MOD - 2);

    for (int i = k; i >= 0; i--)
        for (int j = k; j >= 0; j--)
            if (i + j >= k)
                d[i][j] = (i + j + pa * pb1) % MOD;
            else
                d[i][j] = (d[i][j + 1] * pa + d[i + j][j] * pb) % MOD * p1 % MOD;

    cout << d[0][1];
}