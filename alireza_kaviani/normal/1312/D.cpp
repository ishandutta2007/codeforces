/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; // 998244353; // 1e9 + 9;

ll n , m , ans , fact[MAXN] , inv[MAXN];

ll C(ll r , ll n){
    if(r < 0 || r > n)  return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = inv[0] = 1;
    for(ll i = 1 ; i < MAXN ; i++)  fact[i] = fact[i - 1] * i % MOD;
    for(ll i = 1 ; i < MAXN ; i++)  inv[i] = poww(fact[i] , MOD - 2 , MOD);

    cin >> n >> m;
    if(n == 2)  return cout << 0 << endl , 0;
    for(ll i = 1 ; i <= m ; i++){
        ans += (n - 2) % MOD * C(n - 2 , i - 1) % MOD * poww(2 , n - 3 , MOD) % MOD;
    }
    cout << ans % MOD << endl;

    return 0;
}
/*

*/