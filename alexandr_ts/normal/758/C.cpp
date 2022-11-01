#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 1;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

ll n, m, k, x, y;

ll cnt(ll a, ll b) {
    ll full = k / ((2 * n - 2) * m);
    ll ans = 0;
    if (a == 1 || a == n)
        ans += full;
    else
        ans += full * 2;
    ll k1 = k % ((2 * n - 2) * m);
    if ((a - 1) * m + b <= k1)
        ans++;
    if (k1 > n * m) {
        k1 -= n * m;
        if (a < n) {
            if ((n - a - 1) * m + b <= k1)
                ans++;
        }
    }
    return ans;
}


int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> x >> y;
    if (n == 1) {
        ll c = k / m;
        ll r = k % m;
        if (r)
            cout << c + 1 << endl;
        else
            cout << c << endl;
        cout << c << endl;
        if (r >= y)
            cout << c + 1 << endl;
        else
            cout << c << endl;
        return 0;
    }
    cout << max(max(cnt(1, 1), cnt(2, 1)), cnt(n - 1, 1)) << endl;
    cout << cnt(n, m) << endl;
    cout << cnt(x, y) << endl;
}