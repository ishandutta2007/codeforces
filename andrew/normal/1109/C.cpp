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
    bool us;
    int tl, tr, last_s;
    ll sum, min_pref, pref_sum;
    node *l, *r;
    node(int le, int ri): tl(le), tr(ri), pref_sum(ri - le + 1), last_s(0), sum(0), min_pref(0), us(0), l(r=nullptr){}
};

struct nd{
    bool us;
    int tl, tr, last_s;
    ll sum, min_pref, pref_sum;
};

ll pos;
pll val;

node *root;

nd rt, res;

nd add(node *a, ll last_s){
    res.sum = a -> sum + last_s * a -> pref_sum;
    res.min_pref = a -> min_pref;
    if(a -> pref_sum){
        res.min_pref = min(a -> min_pref, 0ll);
        res.min_pref += last_s * (a -> pref_sum);
        res.min_pref = min(res.min_pref, last_s);
    }
    return res;
}
ll RM;

void unite(node *a, node *l, node *r){
    a -> tl = l -> tl;
    a -> tr = r -> tr;
    a -> us = l -> us | r -> us;
    a -> sum = l -> sum + r -> sum;
    RM = r -> min_pref;
    if(l -> us && r -> pref_sum){
        RM = min(RM, 0ll);
        RM += (l -> last_s) * (r -> pref_sum);
        RM = min(RM, ll(l -> last_s));
        a -> sum += (l -> last_s) * (r -> pref_sum);
    }
    a -> l = l;
    a -> r = r;

    a -> min_pref = min(l -> min_pref, l -> sum + RM);
    a -> pref_sum = l -> pref_sum;
    if(l -> pref_sum == l -> tr - l -> tl + 1)a -> pref_sum += r -> pref_sum;

    if(r -> us)a -> last_s = r -> last_s;
    else a -> last_s = l -> last_s;
}

void modify(node *v){
    if(v -> tl == v -> tr){
        v -> us = val.se;
        v -> last_s = val.fi;
        if(val.se){
            v -> sum = v -> min_pref = val.fi;
            v -> pref_sum = 0;
        }else{
            v -> sum = v -> min_pref = 0;
            v -> pref_sum = 1;
        }
        return;
    }
    int tm = (v -> tl + v -> tr) >> 1;

    if(v -> l == nullptr){
        v -> l = new node(v -> tl, tm);
    }

    if(v -> r == nullptr){
        v -> r = new node(tm + 1, v -> tr);
    }

    if(pos <= tm)modify(v -> l);
    else modify(v -> r);
    unite(v, v -> l, v -> r);

}

node *Ans;

ll V;

bool ok;

ld ans = -1;
ll last_S;
void dfs(node *v){
    if(v -> tl == v -> tr){
        ok = 1;
        ans = v -> tl - 1;
        if(v -> us)last_S = v -> last_s;
        if(last_S != 0)ans += ld(V) / -last_S;
        return;
    }
    int tm = (v -> tl + v -> tr) >> 1;
    if(v -> l == nullptr){
        v -> l = new node(v -> tl, tm);
    }

    if(v -> r == nullptr){
        v -> r = new node(tm + 1, v -> tr);
    }

    rt = add(v -> l, last_S);

    if(!V || rt.min_pref + V <= 0)dfs(v -> l); else{
        V += rt.sum;
        if((v -> l) -> us)last_S = (v -> l) -> last_s;
        dfs(v -> r);
    }

}
void get(node *v, int l, int r){
    if(l > r)return;
    if(ok)return;
    if(v -> tl == l && v -> tr == r){
        rt = add(v, last_S);
        if(!V || V + rt.min_pref <= 0){
            dfs(v);
        }else{
            V += rt.sum;
            if(v -> us)last_S = v -> last_s;
        }
        return;
    }
    int tm = (v -> tl + v -> tr) >> 1;
    if(v -> l == nullptr){
        v -> l = new node(v -> tl, tm);
    }

    if(v -> r == nullptr){
        v -> r = new node(tm + 1, v -> tr);
    }
    get(v -> l, l, min(r, tm));
    get(v -> r, max(tm + 1, l), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    root = new node(1, 1e9);

    while(q--){
        short t;
        cin >> t;
        if(t == 1){
            int s;
            cin >> pos >> s;
            val = {s, 1};
            modify(root);
        }else if(t == 2){
            cin >> pos;
            val = {0ll, 0ll};
            modify(root);
        }else {
            ok = 0;
            ans = -1;
            last_S = 0;
            int l, r;
            cin >> l >> r >> V;
            get(root, l, r - 1);
            if(!ok)cout << "-1\n"; else cout << fixed << setprecision(6) << ans + 1 << "\n";
        }

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}