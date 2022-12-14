/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-16 21:31:29
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

const ll MAXN = 5e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , timer , p[MAXN] , st[MAXN] , fn[MAXN] , par[LOG][MAXN] , mark[MAXN];
ll ans[MAXN] , cnt[MAXN] , H[MAXN];
vector<int> adj[MAXN] , V[MAXN];

void DFS(int v , int p = 0){
    H[v] = (v == 0 ? 0 : H[p] + 1);
    st[v] = ++timer;
    par[0][v] = p;
    V[H[v]].push_back(v);
    for(int u : adj[v]) if(u != v)  DFS(u , v);
    fn[v] = timer;
}

int getPar(int v , int h){
    for(int i = 0 ; i < LOG ; i++)  if(h & (1 << i))    v = par[i][v];
    return v;
}

int LCA(int v , int u){
    if(H[v] > H[u]) swap(v , u);
    u = getPar(u , H[u] - H[v]);
    if(u == v)  return u;
    for(int i = LOG - 1 ; i >= 0 ; i--) if(par[i][v] != par[i][u])  v = par[i][v] , u = par[i][u];
    return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    DFS(0);

    for(int i = 1 ; i < LOG ; i++){
        for(int j = 1 ; j <= n ; j++)   par[i][j] = par[i - 1][par[i - 1][j]];
    }

    //for(int i = 1 ; i <= n ; i++)   cout << H[i] << sep;
    //cout << endl;
    for(int i = 2 ; i <= n ; i++){
        if(SZ(V[i]) == 0)   continue;
        vector<pair<int , int>> vec;
        for(int j = 0 ; j < SZ(V[i]) ; j++){
            ans[V[i][j]] = ans[par[0][V[i][j]]];
            if(!mark[V[i][j]]){
                vec.push_back({st[V[i][j]] , V[i][j]});
                mark[V[i][j]] = 1;
            }
            if(j + 1 < SZ(V[i])){
                int lca = LCA(V[i][j] , V[i][j + 1]);
                if(!mark[lca]){
                    vec.push_back({st[lca] , lca});
                    mark[lca] = 1;
                }
            }
        }
        sort(all(vec));
        for(pair<int , int> j : vec)    p[j.Y] = cnt[j.Y] = 0;
        vector<int> stk;
        stk.push_back(vec[0].Y);
        for(int j = 1 ; j < SZ(vec) ; j++){
            while(fn[stk.back()] < fn[vec[j].Y])  stk.pop_back();
            p[vec[j].Y] = stk.back();
            stk.push_back(vec[j].Y);
        }
        reverse(all(vec));
        for(int j : V[i])   cnt[j] = 1;
        for(pair<int , int> j : vec)    cnt[p[j.Y]] += cnt[j.Y];
        cnt[0] = 0;
        reverse(all(vec));
        for(pair<int , int> j : vec){
            mark[j.Y] = 0;
            cnt[j.Y] = cnt[p[j.Y]] + cnt[j.Y] * (H[j.Y] - H[p[j.Y]]);
            //cout << j.X << sep << j.Y << sep << cnt[j.Y] << endl;
            if(H[j.Y] == i) ans[j.Y] += cnt[j.Y] - 1;
        }
        //cout << "============" << endl;
    }
    for(int i = 1 ; i <= n ; i++)   cout << ans[i] << sep;

    return 0;
}
/*

*/