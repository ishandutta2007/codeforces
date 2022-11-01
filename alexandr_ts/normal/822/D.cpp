#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e3 + 2;
const int N = 5e6 + 12;

bool prime[N];

ll d[N];
ll pw[N];
int mind[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    ll t, l, r;
    cin >> t >> l >> r;
    pw[0] = 1;
    frab(i, 1, N)
        pw[i] = (pw[i - 1] * t) % MOD;

    frab(i, 2, N)
        if (!prime[i])
            for (ll j = i * i; j < N; j += i)
                prime[j] = true;

    frab(i, 2, N)
        if (!prime[i])
            for (ll j = 2 * i; j < N; j += i)
                if (!mind[j])
                    mind[j] = i;

    frab(i, 2, N) {
        if (!prime[i]) {
            d[i] = ((i * (i - 1)) / 2) % MOD;
        }
        else {
            ll dv = mind[i];
            d[i] = (d[i / dv] + i * (dv - 1) / 2) % MOD;
        }
    }

    ll ans = 0;
    frab(i, l, r + 1)
        ans = (ans + pw[i - l] * d[i]) % MOD;
    cout << ans;
}