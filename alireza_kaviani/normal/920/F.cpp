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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , D[MAXN] , val[MAXN] , fen[MAXN] , par[MAXN];

ll Find(ll v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}
void Union(ll v , ll u){
    v = Find(v) , u = Find(u);
    if(v < u)   swap(v , u);
    if(u == v)  return;
    par[u] = v;
}

void add(ll x , ll val){
    for( ; x < MAXN ; x += x & -x)  fen[x] += val;
}
ll get(ll x){
    ll ans = 0;
    for( ; x > 0 ; x -= x & -x) ans += fen[x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(par , par + MAXN , -1);

    for(ll i = 1 ; i < MAXN ; i++){
        for(ll j = i ; j < MAXN ; j += i)   D[j]++;
    }

    cin >> n >> q;
    for(ll i = 1 ; i <= n ; i++)    cin >> val[i] , add(i , val[i]);

    while(q--){
        ll t , l , r;
        cin >> t >> l >> r;
        if(t == 1){
            for(ll i = l ; i <= r ; i++ , i = Find(i)){
                add(i , -val[i]);
                val[i] = D[val[i]];
                add(i , val[i]);
                if(val[i] <= 2) Union(i , i + 1);
            }
        }
        else{
            cout << get(r) - get(l - 1) << endl;
        }
    }

    return 0;
}
/*

*/