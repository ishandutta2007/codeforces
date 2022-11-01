#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

ll calc(ll n, ll m, ll x, ll y) {
    if (x < 0 || y < 0)
        return 0;
    return (n / (x + 1)) * (m / (y + 1));
}

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, m, k;
    cin >> n >> m >> k;

    if (n < m)
        swap(n, m);

    ll ans = 0;

    frab(i, -1000, 1) {
        ll tmp = min(n - 1, k) + i;
        ans = max(ans, calc(n, m, tmp, k - tmp));
    }
    swap(n, m);
    frab(i, -1000, 1) {
        ll tmp = min(n - 1, k) + i;
        ans = max(ans, calc(n, m, tmp, k - tmp));
    }

    if (!ans)
        cout << -1;
    else
        cout << ans;

}