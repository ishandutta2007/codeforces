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
    int tl, tr;
    ll ans;
    vector <pii> suf, pref;
    node *l, *r;
    node(): tl(0), tr(0), ans(0), l(r=nullptr){}
};

int X, uk, last, Val;

node *root = new node();

vector <ll> a;

node *unite(node *l, node *r){
    node *res = new node();
    if(l == nullptr){
        res -> tl = r -> tl;
        res -> tr = r -> tr;
        res -> suf = r -> suf;
        res -> pref = r -> pref;
        res -> ans = r -> ans;
        return res;
    }

    if(r == nullptr){
        res -> tl = l -> tl;
        res -> tr = l -> tr;
        res -> suf = l -> suf;
        res -> pref = l -> pref;
        res -> ans = l -> ans;
        return res;
    }

    res -> tl = l -> tl;
    res -> tr = r -> tr;
    res -> ans = l -> ans + r -> ans;
    res -> l = l;
    res -> r = r;

    uk = ll(r -> pref.size()) - 1;

    last = r -> tl;

    for(int i = 0; i < l -> suf.size(); i++){
        int val = l -> suf[i].fi;
        if((val | r -> pref.back().fi) >= X){
            while(uk > 0 && (val | (r -> pref[uk - 1].fi)) >= X)uk--;
            res -> ans += ll(last - l -> suf[i].se) * ll(r -> tr - (r -> pref[uk].se) + 1);
        }
        last = l -> suf[i].se;
    }

    res -> pref = l -> pref;
    for(auto i : r -> pref){
        Val = i.fi | (res -> pref.back().fi);
        if(Val != res -> pref.back().fi){
            res -> pref.p_b({Val, i.se});
        }
    }

    res -> suf = r -> suf;

    for(auto i : l -> suf){
        Val = i.fi | (res -> suf.back().fi);
        if(Val != res -> suf.back().fi){
            res -> suf.p_b({Val, i.se});
        }else{
            res -> suf.pop_back();
            res -> suf.p_b({Val, i.se});
        }
    }

    return res;

}

void build(node *&v){
    if(v -> tl == v -> tr){
        v -> suf.p_b({a[v -> tl], v -> tl});
        v -> pref.p_b({a[v -> tl], v -> tl});
        if(a[v -> tl] >= X)v -> ans = 1;
    }else{
        ll tm = (v -> tl + v -> tr) >> 1;
        v -> l = new node();
        (v -> l) -> tl = v -> tl;
        (v -> l) -> tr = tm;
        build(v -> l);
        v -> r = new node();
        (v -> r) -> tl = tm + 1;
        (v -> r) -> tr = v -> tr;
        build(v -> r);
        v = unite(v -> l, v -> r);

    }
}

int pos, val;

void modify(node *&v){
    if(v -> tl == v -> tr){
        v -> suf.clear();
        v -> pref.clear();
        v -> suf.p_b({val, v -> tl});
        v -> pref.p_b({val, v -> tl});
        if(val >= X)v -> ans = 1; else v -> ans = 0;
    }else{
        int tm = (v -> tl + v -> tr) >> 1;
        if(pos <= tm)modify(v -> l);
        else modify(v -> r);
        v -> pref.clear();
        v -> suf.clear();
        delete(v);
        v = unite(v -> l, v -> r);
    }
}

node *Ans, *rt;

void get(node *v, int l, int r){
    if(l > r)return;
    if(v -> tl == l && v -> tr == r){
        rt = unite(Ans, v);
        if(Ans != nullptr){
            Ans -> pref.clear();
            Ans -> suf.clear();
            delete(Ans);
        }
        Ans = rt;
        return;
    }
    int tm = (v -> tl + v -> tr) >> 1;
    get(v -> l, l, min(r, tm));
    get(v -> r, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m >> X;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    root -> tl = 1;
    root -> tr = n;

    build(root);

    while(m--){
        short t;
        cin >> t;
        if(t == 1){
            cin >> pos >> val;
            modify(root);
        }else{
            int l, r;
            cin >> l >> r;
            Ans = nullptr;
            get(root, l, r);
            cout << Ans -> ans << "\n";

        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}