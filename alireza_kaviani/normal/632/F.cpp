#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int ll;
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

const ll MAXN = 2.5e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , A[MAXN][MAXN];
bitset<MAXN> r[MAXN];
vector<ll> vec;
vector<pll> ind[MAXN * MAXN];

int main() {
    fast_io;

    scanf("%d" , &n);
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            scanf("%d" , &A[i][j]);
            vec.push_back(A[i][j]);
        }
    }

    for(ll i = 1 ; i <= n ; i++)    if(A[i][i] != 0)    return cout << "NOT MAGIC" << endl , 0;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            if(A[i][j] != A[j][i])  return cout << "NOT MAGIC" << endl , 0;
        }
    }

    Sort(vec);
    vec.resize(unique(all(vec)) - vec.begin());

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            A[i][j] = lower_bound(all(vec) , A[i][j]) - vec.begin();
            ind[A[i][j]].emplace_back(i , j);
        }
    }

    for(ll i = 0 ; i <= n * n ; i++){
        for(pll j : ind[i]){
            if((r[j.X] & r[j.Y]).count() != 0)  return cout << "NOT MAGIC" << endl , 0;
        }
        for(pll j : ind[i]) r[j.X][j.Y] = 1;
    }

    cout << "MAGIC" << endl;

    return 0;
}
/*

*/