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
 
struct node{
    ll t;
};
 
node T[2 * MAXN];
 
void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        T[v].t = val;
    }else{
        ll tm = (tl + tr) >> 1;
        if(T[v].t != -1){
            T[v << 1].t = max(T[v << 1].t, T[v].t);
            T[(v << 1) + 1].t = max(T[(v << 1) + 1].t, T[v].t);
            T[v].t = -1;
        }
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify((v << 1) + 1, tm + 1, tr, pos, val);
    }
}
 
vector <ll> a;
 
void build(ll v, ll tl, ll tr){
    T[v].t = -1;
    if(tl == tr)T[v].t = a[tl]; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
    }
}
 
void calc(ll v, ll tl, ll tr){
    if(tl == tr)cout << T[v].t << " ";
    else{
        ll tm = (tl + tr) >> 1;
        if(T[v].t != -1){
            T[v << 1].t = max(T[v << 1].t, T[v].t);
            T[(v << 1) + 1].t = max(T[(v << 1) + 1].t, T[v].t);
            T[v].t = -1;
        }
        calc(v << 1, tl, tm);
        calc((v << 1) + 1, tm + 1, tr);
    }
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    a.resize(n + 1);
 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
 
 
    build(1, 1, n);
 
    ll q;
    cin >> q;
 
    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll pos, val;
            cin >> pos >> val;
            modify(1, 1, n, pos, val);
        }else{
            ll x;
            cin >> x;
            T[1].t = max(T[1].t, x);
        }
    }
 
    calc(1, 1, n);
    cout << "\n";
    return 0;
}