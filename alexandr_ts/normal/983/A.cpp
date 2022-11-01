#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-14;
const ld PI = acos(-1);
const ll M = 1e3 + 10;
const int N = 1e6 + 10;


void solve() {
    ios_base::sync_with_stdio(false);
    ll n, p, q, b;
    cin >> n;
    while (n--) {
        cin >> p >> q >> b;
        p %= q;
        ll gcd = __gcd(p, q);
        p /= gcd;
        q /= gcd;
        if (p == 0) {
            cout << "Finite\n";
            continue;
        }
        ll g = __gcd(b, q);
        while (q % g == 0 && g > 1) {
            while (q % g == 0) {
                q /= g;
            }
            g = __gcd(b, q);
        }
        if (q != 1)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();

}