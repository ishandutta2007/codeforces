#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 1;
const ll INF = 1000000000000ll;
const ld EPS = 1e-9;

ll a[21][N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k, q, t;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[1][i];
    for (ll i = 2; i <= 20; i++)
        for (ll j = 0; j < n; j++)
            a[i][j] = a[1][j] * i;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        cin >> t;
        ll ans = INF;
        for (ll i1 = 1; i1 <= 20; i1++) {
            if (i1 > ans)
                break;
            for (ll j = 0; j < n; j++)
                if (t < a[i1][j])
                    break;
                else
                {
                    for (ll i2 = 0; i2 <= 20 - i1 + 1; i2++) {
                        ll q = *lower_bound(a[i2], a[i2] + n, t - a[i1][j]);
                        //cout << q << endl;
                        if (q == t - a[i1][j] && i1 + i2 <= k)
                            //cout << q << " " << t << " " << a[i1][j] << endl;
                            ans = min(i1 + i2, ans);
                    }

                }
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}