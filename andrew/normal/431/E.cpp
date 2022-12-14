#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e9;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

struct node{
    ll t;
    int t1;
    node *l, *r;
    node(): t(0), t1(0), l(r=nullptr) {}
};

pli val;

int pos;

void modify(node *v, int tl, int tr){
    v -> t += val.fi;
    v -> t1 += val.se;
    if(tl != tr){
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr)v -> l = new node();
            modify(v -> l, tl, tm);
        }else{
            if(v -> r == nullptr)v -> r = new node();
            modify(v -> r, tm + 1, tr);
        }
    }
}

pli unite(pli a, pli b){
    return {a.fi + b.fi, a.se + b.se};
}

pli Val(node *v){
    if(v == nullptr)return {0, 0};
    return {v -> t, v -> t1};
}

ll x;

ll V = 0, kek;

ll _find(node *v, int tl, int tr, pli S){
    if(tl == tr){
        if(v != nullptr)S = unite(S, {v -> t, v -> t1});
        V = ll(tl) * S.se - S.fi;
        kek = S.se;
        return tl;
    }

    int tm = (tl + tr) >> 1;

    if(v == nullptr){
        ll c = tm + 1;
        if(c * S.se - S.fi <= x)return _find(v, tm + 1, tr, S);
        return _find(v, tl, tm, S);
    }else{
        ll c = tm + 1;
        pll C = unite(S, Val(v -> l));
        if(c * C.se - C.fi <= x)return _find(v -> r, tm + 1, tr, C);
        return _find(v -> l, tl, tm, S);
    }
}

node *root = new node();

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector <int> h(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> h[i];
        pos = h[i];
        val = {h[i], 1};
        modify(root, 0, N);
    }

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int p, x;
            cin >> p >> x;
            pos = h[p];
            val = {-h[p], -1};
            modify(root, 0, N);
            h[p] = x;
            pos = h[p];
            val = {h[p], 1};
            modify(root, 0, N);
        }else{
            cin >> x;
            ll l = _find(root, 0, N, {0, 0});
            ld g = l;
            x -= V;
            g += ld(x) / ld(kek);
            cout << fixed << setprecision(4) << g << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}