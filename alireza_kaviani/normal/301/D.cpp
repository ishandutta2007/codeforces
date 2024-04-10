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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , P[MAXN] , ind[MAXN] , ans[MAXN] , fen[MAXN];
vector<ll> dv[MAXN];
vector<pll> Q[MAXN];

void update(ll x , ll val){
    for( ; x < MAXN ; x += x & -x)  fen[x] += val;
}
ll get(ll x){
    ll ans = 0;
    for( ; x > 0 ; x -= x & -x) ans += fen[x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(ll i = 1 ; i < MAXN ; i++){
        for(ll j = i ; j < MAXN ; j += i)   dv[j].push_back(i);
    }

    cin >> n >> q;
    for(ll i = 1 ; i <= n ; i++){
        cin >> P[i];
        ind[P[i]] = i;
    }
    for(ll i = 1 ; i <= q ; i++){
        ll l , r ; cin >> l >> r;
        Q[l].push_back({r , i});
    }

    for(ll i = 1 ; i <= n ; i++){
        ll cnt = 0;
        for(ll j : dv[i])   if(ind[i] >= ind[j]) cnt++;
        for(ll j = i ; j <= n ; j += i) if(ind[i] > ind[j]) cnt++;
        update(ind[i] , cnt);
    }

    for(ll i = 1 ; i <= n ; i++){
        for(pll j : Q[i]){
            ans[j.Y] = get(j.X);
        }
        for(ll j : dv[P[i]])   if(i <= ind[j])    update(ind[j] , -1);
        for(ll j = P[i] ; j <= n ; j += P[i])   if(i < ind[j])  update(ind[j] , -1);
    }
    for(ll i = 1 ; i <= q ; i++)    cout << ans[i] << endl;

    return 0;
}
/*

*/