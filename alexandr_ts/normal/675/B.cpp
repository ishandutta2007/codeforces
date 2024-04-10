#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

ll a[3][3];

bool ok(ll x, ll n) {
    return x >= 1 && x <= n;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll ans = 0;
    frab(i, 1, n + 1) {
        if (ok(b + i - c, n) && ok(a + b + i - c - d, n) && ok(a + i - d, n))
            ans++;
    }
    cout << ans * n;

}