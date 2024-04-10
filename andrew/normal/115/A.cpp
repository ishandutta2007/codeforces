#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll ans[MAXN], p[MAXN];
 
vector <ll> v[MAXN];
 
ll res = 0;
 
void dfs(ll x, ll pr, ll deep = 1){
    res = max(res, deep);
    for(auto to : v[x])dfs(to, x, deep + 1);
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] != -1)v[p[i]].p_b(i);
    }
 
    for(int i = 1; i <= n; i++)if(p[i] == -1){
        dfs(i, -1ll);
    }
 
    cout << res << endl;
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}