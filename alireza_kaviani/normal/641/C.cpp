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

ll n , q , odd , even , type , x , ans[MAXN];

int main() {
    fast_io;

    cin >> n >> q;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> x;
            x = (x + 10 * n) % n;
            odd += x;
            even += x;
        }
        if(type == 2){
            if(odd % 2 == 1)    odd--;
            else odd++;
            if(even % 2 == 0)   even--;
            else even++;
        }
    }

    for(ll i = 1 ; i <= n ; i++){
        ll t = (i + (i % 2 == 1 ? odd : even) + MAXN * n) % n;
        if(t == 0)  t = n;
        ans[t] = i;
    }
    for(ll i = 1 ; i <= n ; i++)    cout << ans[i] << sep;

    return 0;
}
/*

*/