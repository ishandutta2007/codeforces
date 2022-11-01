#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 1;
const ld EPS = 1e-8;
const ll MAX = 1e6;
const int N = 5e3 + 2;

ll d[N][N];

void add(ll &x, ll val) {
    x += val;
    x %= MOD;
}

ll pw(int p) {
    if (p == 0) return 1;
    if (p % 2) return 2 * pw(p - 1) % MOD;
    ll ans = pw(p / 2);
    return ans * ans % MOD;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    ll n, k;
    cin >> n >> k;
    d[0][0] = 1;

    for (int i = 0; i < k; i++)
        for (int j = 0; j <= min(n, k); j++) {
            if (!d[i][j]) continue;
            add(d[i + 1][j], d[i][j] * j);
            add(d[i + 1][j + 1], d[i][j] * (n - j));
        }

    ll ans = 0;
    for (int i = 0; i <= min(n, k); i++)
        add(ans, d[k][i] * pw(n - i));
    cout << ans;


}