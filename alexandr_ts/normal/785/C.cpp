#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2001;
const ld EPS = 1e-8;
const ll INF = 2e9 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    ll n, m;
    cin >> n >> m;
    if (m >= n) {
        cout << n;
        return 0;
    }
    ll k = (sqrt((ld)(8ll * (n - m) + 1ll)) - 1ll) / 2ll;
    for (ll i = -5; i <= 5; i++) if (k + i >= 1)
        if ((k + i) * (k + i + 1) >= 2 * (n - m)) {
            cout << k + i + m;
            return 0;
        }
}