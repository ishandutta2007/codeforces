#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e6 + 10;
const int M = 1e3 + 10;




int main() {
    //freopen("a.in", "r", stdin);
    ll n, t, k, d;
    cin >> n >> t >> k >> d;
    ll t1 = (n + k - 1) / k * t;

    ll ans = (t1 - 1) / t * k + k * ((t1 - 1 - d) / t);

    if (ans >= n && t1 >= d)
        cout << "YES";
    else
        cout << "NO";

}