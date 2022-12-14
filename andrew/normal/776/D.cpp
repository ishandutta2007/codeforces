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
 
vector <ll> v[MAXN], g[MAXN];
 
ll a[MAXN], kol[MAXN];
ll was[MAXN], step;
ll Kol[MAXN];
 
void click(ll x){
    for(auto i : g[x])a[i] = 1 - a[i];
 
    for(auto i : g[x])if(!a[i]){
        Kol[i]++;
        if(Kol[i] > 15)vout("NO");
        if(v[i].back() == x){
            click(v[i][0]);
        }else{
            click(v[i].back());
        }
    }
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    for(int i = 1; i <= n; i++)cin >> a[i];
 
    for(int i = 0; i < m; i++){
        ll k;
        cin >> k;
        while(k--){
            ll x;
            cin >> x;
            g[i].p_b(x);
        }
    }
 
    shuffle(g, g + m, rnd);
 
    for(int i = 0; i < m; i++){
        for(auto j : g[i])v[j].p_b(i);
    }
 
    for(step = 0; step < m; step++){
        ll fa, fb;
        fa = fb = 0;
        for(auto i : g[step]){
            if(v[i].back() == step){
                if(a[i] == 0)fa = 1;
            }
        }
 
        if(fa){
            for(auto i : g[step]){
                a[i] = 1 - a[i];
            }
            for(auto i : g[step])if(!a[i] && v[i].back() == step){
                click(v[i][0]);
            }
        }
    }
 
    for(int i = 1; i <= n; i++)if(!a[i])vout("NO");
    vout("YES");
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}