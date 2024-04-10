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

ll k , deg[MAXN];
vector<pll> E;

void addEdges(ll v , ll l , ll r){
    for(ll i = l ; i <= r ; i++){
        E.push_back({v , i});
        deg[i]--;
    }
}

void addComp(ll l , ll r){
    addEdges(l , l + 1 , l + deg[l]);
    for(ll i = l + 1 ; i <= r ; i++){
        ll L = i + 2 - i % 2;
        addEdges(i , L , L + deg[i] - 1);
    }
}

int main() {
    fast_io;

    cin >> k;
    fill(deg , deg + MAXN , k);
    if(k % 2 == 0)  return cout << "NO" << endl , 0;
    cout << "YES" << endl;
    if(k == 1)  return cout << "2 1\n1 2" << endl , 0;

    deg[k + 2]--;
    deg[2 * (k + 2)]--;
    addComp(1 , k + 2);
    addComp(k + 3 , 2 * (k + 2));
    E.push_back({k + 2 , 2 * (k + 2)});
    
    cout << 2 * k + 4 << sep << E.size() << endl;
    for(pll i : E)  cout << i.X << sep << i.Y << endl;

    return 0;
}
/*

*/