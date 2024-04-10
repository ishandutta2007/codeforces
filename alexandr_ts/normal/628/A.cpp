#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e3;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;

ll a[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    ll n, b, p;
    cin >> n >> b >> p;
    ll n1 = n;
    ll cnt = 0;
    while (n1 > 1) {
        int k = 1;
        while (2 * k <= n1)
            k *= 2;
         //cout << n1 << " " << k << endl;
        cnt += k / 2;
        n1 -= k / 2;
    }
    cout << cnt * (2 * b + 1) << " " << n * p;
}