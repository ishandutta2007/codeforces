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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n = -1 , m = -1 , a[4];
string ans;

int main() {
    fast_io;

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    for(ll i = 0 ; i < 1e5; i++){
        if(i * (i - 1) / 2 == a[0]) n = i;
        if(i * (i - 1) / 2 == a[3]) m = i;
    }

    if(m == -1 || n == -1)  return cout << "Impossible" << endl , 0;
    if(a[1] + a[2] == 0 && a[0] != 0 && a[3] == 0)   return cout << string(n , '0') << endl , 0;
    if(a[1] + a[2] == 0 && a[0] == 0)   return cout << string(m , '1') << endl , 0;
    if(n * m != a[1] + a[2])    return cout << "Impossible" << endl , 0;
    
    ans = string(n , '0');
    ans += string(a[1] / n , '1');
    if(ans.size() == n + m) return cout << ans << endl , 0;
    
    m -= a[1] / n;
    a[1] %= n;
    ans = ans.substr(0 , a[1]) + "1" + ans.substr(a[1] , SZ(ans));
    ans = string(m - 1 , '1') + ans;
    cout << ans << endl;

    return 0;
}
/*

*/