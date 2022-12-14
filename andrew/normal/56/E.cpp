#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 gen;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

struct node{
    ll Val;
    node *l, *r;
    node(ll x): Val(x), l(r=nullptr){}
};

struct qry{
    ll pos, x, h;
};

inline bool operator <(qry a, qry b){
    return (a.x < b.x);
}

inline bool operator >(qry a, qry b){
    return (a.x > b.x);
}

void modify(node *v, ll tl, ll tr, ll pos, ll val){
    v -> Val = max(v -> Val, val);
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr)v -> l = new node(-1e9);
            modify(v -> l, tl, tm, pos, val);
        }else{
            if(v -> r == nullptr)v -> r = new node(-1e9);
            modify(v -> r, tm + 1, tr, pos, val);
        }
    }
}

ll get(node *v, ll tl, ll tr, ll l, ll r){
    if(l > r)return -1e9;
    if(v == nullptr)return -1e9;
    if(tl == l && tr == r)return v -> Val;
    ll tm = (tl + tr) >> 1;
    return max(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

void update(node *v, ll tl, ll tr, ll pos, ll val){
    v -> Val += val;
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr)v -> l = new node(0ll);
            update(v -> l, tl, tm, pos, val);
        }else{
            if(v -> r == nullptr)v -> r = new node(0ll);
            update(v -> r, tm + 1, tr, pos, val);
        }
    }
}

ll f(node *v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(v == nullptr)return 0;
    if(tl == l && tr == r)return v -> Val;
    ll tm = (tl + tr) >> 1;
    return f(v -> l, tl, tm, l, min(r, tm)) + f(v -> r, tm + 1, tr, max(l, tm + 1), r);
}

ll dp[MAXN], ans[MAXN];

node *root = new node(-1e9), *root1 = new node(0);

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;
    vector <qry> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i].x >> c[i].h;
        c[i].pos = i;
    }

    sort(all(c));

    for(int i = n - 1; i >= 0; i--){
        dp[i] = max(get(root, -1e9, 1e9, c[i].x + 1, c[i].x + c[i].h - 1), c[i].x + c[i].h - 1);
        update(root1, -1e9, 1e9, c[i].x, 1);
        ans[c[i].pos] = f(root1, -1e9, 1e9, c[i].x, dp[i]);
        modify(root, -1e9, 1e9, c[i].x, dp[i]);
    }

    for(int i = 0; i < n; i++)cout << ans[i] << " ";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}