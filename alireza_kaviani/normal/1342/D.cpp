/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-26 19:05:03
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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

ll n , k , ans , M[MAXN] , C[MAXN];
vector<ll> v[MAXN];
set<pll> st;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++) cin >> M[i] , st.insert({k - M[i] , i});
    for(ll i = 0 ; i < k ; i++) cin >> C[i];
    reverse(C , C + k);

    while(SZ(st)){
        ans++;
        ll cnt = 0;
        while(1){
            cnt++;
            ll ind = lower_bound(C , C + k , cnt) - C;
            auto it = st.lower_bound({ind , -INF});
            if(it == st.end())  break;
            v[ans].push_back(k - (*it).X);
            st.erase(it);
        }
        /*cout << SZ(v) << sep;
        for(ll i : v)   cout << i << sep;
        cout << endl;*/
    }
    
    cout << ans << endl;
    for(ll i = 1 ; i <= ans ; i++){
        cout << SZ(v[i]) << sep;
        for(ll j : v[i])    cout << j << sep;
        cout << endl;
    }

    return 0;
}
/*

*/