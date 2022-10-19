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

ll n , m , v , u , w , last , ans , dp[MAXN][2];
vector<pair<ll , pll>> E;
vector<ll> vec;

int main() {
    fast_io;
    
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        cin >> v >> u >> w;
        E.push_back({w , {v , u}});
    }
    sort(all(E) , greater<pair<ll , pll>>());
    
    for(pair<ll , pll> i : E){
        if(i.X != last){
            for(ll j : vec){
                dp[j][0] = max(dp[j][0] , dp[j][1]);
                dp[j][1] = 0;
            }
            vec = {};
        }
        v = i.Y.X , u = i.Y.Y;
        dp[v][1] = max(dp[v][1] , dp[u][0] + 1);
        vec.push_back(v);
        last = i.X;
    }
    
    for(ll i = 0 ; i < MAXN ; i++)  ans = max({ans , dp[i][0] , dp[i][1]});
    cout << ans << endl;

    return 0;
}
/*

*/