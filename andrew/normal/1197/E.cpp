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
#define delete _delete

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e9 + 5;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll add(ll a, ll b){
    return (a + b >= mod ? a + b - mod : a + b);
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

void u(int &a, int b){
    a = add(a, b);
}

struct Set{
    int a, b;
    Set(int x, int y): a(x), b(y){}
};

Set res = *new Set(0, 0);

Set merge(Set a, Set b){
    res.a = 1e9 + 5;
    res.b = 0;
    res.a = min(a.a, b.a);
    if(res.a == a.a)u(res.b, a.b);
    if(res.a == b.a)u(res.b, b.b);
    return res;
}


struct node{
    Set t;
    node *l, *r;
    node(): t(*new Set(1e9 + 5, 0)), l(r=nullptr){}
};

node *root = new node();

Set clr = *new Set(1e9 + 5, 0);

Set Val(node *v){
    if(v == nullptr)return clr;
    return v -> t;
}

void modify(node *v, int tl, int tr, int pos, Set val){
    if(tl != tr){
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr) v -> l = new node();
            modify(v -> l, tl, tm, pos, val);
        }else{
            if(v -> r == nullptr) v -> r = new node();
            modify(v -> r, tm + 1, tr, pos, val);
        }
        v -> t = merge(Val(v -> l), Val(v -> r));
    }else{
        v -> t = merge(v -> t, val);
    }
}

Set get(node *v, int tl, int tr, int l, int r){
    if(v == nullptr)return clr;
    if(l > r)return clr;
    if(tl == l && tr == r)return v -> t;
    int tm = (tl + tr) >> 1;
    return merge(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <pii> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    for(int i = 0; i < n; i++)swap(a[i].fi, a[i].se);

    sort(all(a));

    vector <int> suf(n);
    suf[n - 1] = a[n - 1].se;
    for(int i = n - 2; i >= 0; i--){
        suf[i] = min(suf[i + 1], a[i].se);
    }

    Set ans = *new Set(1e9, 0);

    int mx = 0;

    for(int i = 0; i < n; i++)mx = max(mx, a[i].fi);

    int mn = 1e18;

    for(int i = 0; i < n; i++)mn = min(mn, a[i].se);

    Set val = *new Set(1e9, 0);
    for(int i = n - 1; i >= 0; i--){
        if(a[i].se > mx){
            val.a = a[i].fi;
            val.b = 1;
        }else{
            pii kek = {a[i].se, -1e9 - 5};
            int pos = upper_bound(all(a), kek) - a.begin();
            val = get(root, 1, N, a[i].se, suf[pos] - 1);
            val.a += a[i].fi - a[i].se;
        }
        if(a[i].fi <= mn)ans = merge(ans, val);
        modify(root, 1, N, a[i].fi, val);
    }

    cout << ans.b << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}