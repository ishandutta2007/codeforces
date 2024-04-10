#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 18;
const ll M = 1e5;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

ll lux[M];
ll luxa[N][N];
ll d[(1 << N)][N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, m, k;
    cin >> n >> m >> k;
    fr(i, n)
        cin >> lux[i];
    fr(i, k) {
        ll t1, t2, c;
        cin >> t1 >> t2 >> c;
        luxa[t1 - 1][t2 - 1] = c;
    }

    ll ans = 0;

    fr(i, n)
        d[(1 << i)][i] = lux[i];

    frab(mask, 1, (1 << n))
        fr(last, n) {
            if (!(mask & (1 << last)))
                continue;
            if (__builtin_popcount(mask) == m) {
                ans = max(ans, d[mask][last]);
                continue;
            }
            fr(i, n)
                if (!(mask & (1 << i))) {
                    ll tmp = d[mask][last] + lux[i] + luxa[last][i];
                    d[mask | (1 << i)][i] = max(d[mask | (1 << i)][i], tmp);
                }
        }
    cout << ans;
}