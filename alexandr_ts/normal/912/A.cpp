#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e6 + 10;



int main() {
    //freopen("a.in", "r", stdin);
    ll a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    ll n1 = 2 * x + y;
    ll n2 = 3 * z + y;
    cout << max(0ll, n2 - b) + max(0ll, n1 - a);
}