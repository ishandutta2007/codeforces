#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll t;
    cin >> t;
    while (t--) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
//        ll gcd = __gcd(p, q);
//        p /= gcd, q /= gcd;

        if (p == 0 && x != 0) {
            cout << -1 << endl;
            continue;
        }

        if (p == q && y != x) {
            cout << -1 << endl;
            continue;
        }
        
        if (p == q && x == y) {
            cout << 0 << endl;
            continue;
        }

        if (x == 0 && p == 0) {
            cout << 0 << endl;
            continue;
        }

        ll t = (x + p - 1) / p;
        t = max(t, (y + q - 1) / q);
        t = max(t, (y - x + q - p - 1) / (q - p));
        cout << q * t - y << endl;
    }
}