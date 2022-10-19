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

ll n , ans , A[MAXN] , B[MAXN] , fen[MAXN];
vector<ll> p , vec;
map<ll , ll> ind;
Tree<ll> tr;

void add(ll ind , ll x){
    ind++;
    for( ; ind < MAXN ; ind += ind & (-ind))
        fen[ind] += x;
}

ll get(ll ind){
    ll ans = 0;
    ind++;
    for( ; ind > 0 ; ind -= ind & (-ind))
        ans += fen[ind];
    return ans;
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> A[i] >> B[i];
        p.push_back(A[i]);
        p.push_back(A[i] + 1);
        p.push_back(B[i]);
        p.push_back(B[i] + 1);
    }
    sort(all(p));
    p.resize(unique(all(p)) - p.begin());

    for(ll i = 0 ; i < p.size() ; i++){
        vec.push_back(p[i]);
        ind[p[i]] = i;
    }
    vec.push_back(vec.back() + 1);

    for(ll i = 0 ; i < n ; i++){
        swap(p[ind[A[i]]] , p[ind[B[i]]]);
    }

    for(ll i = 0 ; i < p.size() ; i++){
        ll t = (*upper_bound(all(vec) , p[i]) - p[i]);
        ans += (get(MAXN - 10) - get(ind[p[i]])) * t;
        add(ind[p[i]] , t);
    }
    cout << ans << endl;

    return 0;
}
/*

*/