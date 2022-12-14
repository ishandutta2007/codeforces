#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef int ll;
const ll MAXN = 1123456;
const ll N = 1e9;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

struct node{
    ll Min, t1;
    node *l, *r;
    node() : l(r=nullptr),Min(0), t1(0){}
};

node *root;

void push(node *v){
    (v -> l) -> Min += v -> t1;
    (v -> l) -> t1 += v -> t1;
    (v -> r) -> Min += v -> t1;
    (v -> r) -> t1 += v -> t1;
    v -> t1 = 0;
}

void modify(node *v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(tl == l && tr == r){
        v -> Min++;
        v -> t1++;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();
    if(v -> t1)push(v);
    modify(v -> l, tl, tm, l, min(r, tm));
    modify(v -> r, tm + 1, tr, max(l, tm + 1), r);
    v -> Min = min((v -> l) -> Min, (v -> r) -> Min);
}

ll get(node *v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return v -> Min;
    ll tm = (tl + tr) >> 1;
    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();
    if(v -> t1)push(v);
    return min(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    root = new node();

    ll n;

    cin >> n;

    vector < pair <pll, ll> > a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].fi.fi >> a[i].fi.se;
        modify(root, 0, N, a[i].fi.fi, a[i].fi.se);
    }


    for(int i = 0; i < n; i++){
        if(get(root, 0, N, a[i].fi.fi, a[i].fi.se) > 1)vout(i + 1);
    }

    cout << "-1\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}