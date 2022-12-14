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
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

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
#define file_io                     freopen("in.txt" , "r" , stdin) ; freopen("out.txt" , "w" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , q , sum , k , a[MAXN] , cnt1[MAXN] , cnt2[MAXN] , ps[MAXN] , ans[MAXN];
Tree<ll> tr;
vector<pair<pll , ll>> query;
vector<pll> vec;

int main() {
    fast_io;

    cin >> n >> m >> q;
    for(ll i = 1 ; i <= n ; i++)    cin >> a[i];
    for(ll i = 1 ; i <= n ; i++)    cnt1[a[i]]++;
    for(ll i = 1 ; i <= m ; i++)    cnt2[cnt1[i]]++;
    for(ll i = 1 ; i <= m ; i++)    vec.push_back({cnt1[i] , i});
    Sort(vec);

    for(ll i = 0 ; i < MAXN ; i++){
        ps[i] = sum;
        sum += cnt2[i];
    }
    partial_sum(ps , ps + MAXN , ps);

    for(ll i = 0 ; i < q ; i++){
        cin >> k;
        k -= n;
        ll ind = lower_bound(ps , ps + MAXN , k) - ps;
        if(ind == MAXN){
            ans[i] = (k - ps[MAXN - 1]) % m;
            if(ans[i] == 0) ans[i] = m;
            continue;
        }
        query.push_back({{ps[ind] - ps[ind - 1] , k - ps[ind - 1] - 1} , i});
    }

    Sort(query);
    for(ll i = 0 ; i < query.size() ; i++){
        while(tr.size() < query[i].X.X){
            tr.insert(vec[tr.size()].Y);
        }
        ans[query[i].Y] = *tr.find_by_order(query[i].X.Y);
    }

    for(ll i = 0 ; i < q ; i++) cout << ans[i] << endl;

    return 0;
}
/*

*/