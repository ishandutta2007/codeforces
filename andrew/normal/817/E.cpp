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
    ll Kol;
    node *p[2];
    node(): Kol(0){
        for(int i = 0; i < 2; i++)p[i] = nullptr;
    }
};
 
node *root = new node();
 
void add(ll x){
    node *q = root;
    for(int i = 30; i >= 0; i--){
        ll to = ((pw(i) & x) > 0);
        if(q -> p[to] == nullptr)q -> p[to] = new node();
        q = q -> p[to];
        q -> Kol++;
    }
}
 
void er(ll x){
    node *q = root;
    for(int i = 30; i >= 0; i--){
        ll to = ((pw(i) & x) > 0);
        if(q -> p[to] == nullptr)q -> p[to] = new node();
        q = q -> p[to];
        q -> Kol--;
    }
}
 
ll Val(node *q){
    if(q == nullptr)return 0;
    return q -> Kol;
}
 
ll f(ll a, ll b){
    node *q = root;
    ll res = 0;
    for(int i = 30; i >= 0; i--){
        bool fa = ((pw(i) & a) > 0), fb = ((pw(i) & b) > 0);
        ll fc = fa ^ fb;
        if(q -> p[fc] == nullptr)q -> p[fc] = new node();
        if(fb == 1)res += Val(q -> p[1 - fc]);
        q = q -> p[fc];
    }
    return res;
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll q;
    cin >> q;
    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            add(x);
        }else if(t == 2){
            ll x;
            cin >> x;
            er(x);
        }else{
            ll a, b;
            cin >> a >> b;
            cout << f(a, b) << "\n";
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}