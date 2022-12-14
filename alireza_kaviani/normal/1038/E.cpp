/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-01 23:20:52
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

const ll MAXN = 2e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , ans , S , odd , val[MAXN] , sz[MAXN] , mark[MAXN];
vector<pll> adj[MAXN] , vec = {{1 , 1} , {1 , 2} , {1 , 3} , {1 , 4} , {2 , 2} , {2 , 3} , {2 , 4} , {3 , 3} , {3 , 4} , {4 , 4}};
vector<ll> E[MAXN];

/*void Tour(ll v){
    while(ptr[v] < SZ(adj[v])){
        ll u = adj[v][ptr[v]].X , ind = adj[v][ptr[v]].Y;
        ptr[v]++;
        X++;
        if(!mark[ind]){
            T += val[ind];
            C++;
            mark[ind] = 1;
            Tour(u);
        }
    }
}*/

void DFS(ll v){
    mark[v] = 1;
    if(SZ(adj[v]) & 1)  odd++;
    for(pll i : adj[v]){
        ll u = i.X , w = val[i.Y];
        S += w;
        if(!mark[u])    DFS(u);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        ll v , u , w;
        cin >> v >> w >> u;
        if(v > u)   swap(v , u);
        ll ind = 0;
        for(ll j = 0 ; j < 10 ; j++){
            if(pll(v , u) == vec[j])    ind = j;
        }
        E[ind].push_back(w);
    }

    for(ll i = 0 ; i < 10 ; i++)    sort(all(E[i]) , greater<ll>()) , sz[i] = E[i].size();
    for(ll i = 0 ; i < (1 << 10) ; i++){
        for(ll j = 0 ; j < 10 ; j++)    if(i & (1 << j))    sz[j]--;
        ll cnt = 0;
        fill(mark , mark + MAXN , 0);
        fill(adj , adj + MAXN , vector<pll>());
        for(ll j = 0 ; j < 10 ; j++){
            for(ll k = 0 ; k < sz[j] ; k++){
                ll v = vec[j].X , u = vec[j].Y;
                adj[v].push_back({u , ++cnt});
                adj[u].push_back({v , cnt});
                val[cnt] = E[j][k];
            }
        }
        /*for(ll j = 1 ; j <= 4 ; j++){
            fill(mark , mark + MAXN , 0);
            ptr[0] = ptr[1] = ptr[2] = ptr[3] = ptr[4] = 0;
            T = C = X = 0;
            Tour(j);
            if(C * 2 == X)  ans = max(ans , T);
        }*/
        for(ll j = 1 ; j <= 4 ; j++){
            fill(mark , mark + 10 , 0);
            S = odd = 0;
            DFS(j);
            if(odd <= 2)    ans = max(ans , S / 2);

        }
        for(ll j = 0 ; j < 10 ; j++)    if(i & (1 << j))    sz[j]++;
    }
    cout << ans << endl;

    return 0;
}
/*

*/