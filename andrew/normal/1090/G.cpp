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

const ll M = 3e5;

struct node{
    int t, t1;
    node *l, *r;
    node(): l(r=nullptr), t(0), t1(-1) {}
};

void build(node *v, int tl, int tr){
    if(tl == 1)v -> t = 1;
    if(tl != tr){
        int tm = (tl + tr) >> 1;
        v -> l = new node();
        v -> r = new node();
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}

node *td = new node();

void modify(node *v, int tl, int tr, int l, int r, int val){
    if(l > r)return;
    if(tl == l && tr == r){
        v -> t = val * (tr - tl + 1);
        v -> t1 = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    bool fa;
    fa = 0;
    if(v -> t1 != -1){
        td = new node();
        td -> l = (v -> l) -> l;
        td -> r = (v -> l) -> r;
        td -> t = (tm - tl + 1) * v -> t1;
        td -> t1 = v -> t1;
        v -> l = td;

        td = new node();
        td -> l = (v -> r) -> l;
        td -> r = (v -> r) -> r;
        td -> t = (tr - tm) * v -> t1;
        td -> t1 = v -> t1;
        v -> r = td;
        v -> t1 = -1;
        fa = 1;
    }

    if(l <= min(r, tm)){
        if(!fa){
            td = new node();
            td -> l = (v -> l) -> l;
            td -> r = (v -> l) -> r;
            td -> t = (v -> l) -> t;
            td -> t1 = (v -> l) -> t1;
            v -> l = td;
        }
        modify(v -> l, tl, tm, l, min(r, tm), val);
    }

    if(max(l, tm + 1) <= r){
        if(!fa){
            td = new node();
            td -> l = (v -> r) -> l;
            td -> r = (v -> r) -> r;
            td -> t = (v -> r) -> t;
            td -> t1 = (v -> r) -> t1;
            v -> r = td;
        }
        modify(v -> r, tm + 1, tr, max(l, tm + 1), r, val);
    }

    v -> t = (v -> l) -> t + (v -> r) -> t;
}

ll Pos, mb;

void find(node *v, int tl, int tr){
    if(tl > Pos)return;
    if(mb != -1)return;
    if(v -> t == 0)return;
    if(tl == tr){
        mb = tl;
        return;
    }
    int tm = (tl + tr) >> 1;

    if(v -> t1 != -1){
        td = new node();
        td -> l = (v -> l) -> l;
        td -> r = (v -> l) -> r;
        td -> t = (tm - tl + 1) * v -> t1;
        td -> t1 = v -> t1;
        v -> l = td;

        td = new node();
        td -> l = (v -> r) -> l;
        td -> r = (v -> r) -> r;
        td -> t = (tr - tm) * v -> t1;
        td -> t1 = v -> t1;
        v -> r = td;
        v -> t1 = -1;
    }

    find(v -> r, tm + 1, tr);
    find(v -> l, tl, tm);

}

struct hero{
    ll dead = -1, Damage, R;
    node *root;
};

vector <hero> H;

hero nw;

ll st;

void Dec_Hp(ll a, ll damage){
    if(H[a].dead != -1)return;
    if(H[a].R <= damage){
        H[a].dead = st;
        return;
    }
    Pos = H[a].R - damage;
    td = new node();
    td -> l = H[a].root -> l;
    td -> r = H[a].root -> r;
    td -> t = H[a].root -> t;
    td -> t1 = H[a].root -> t1;
    H[a].root = td;
    mb = -1;
    find(H[a].root, 1, M);

    if(mb == -1){
        H[a].dead = st;
        return;
    }

    modify(H[a].root, 1, M, mb, mb, 0);
    modify(H[a].root, 1, M, mb + 1, Pos, 1);

    if(H[a].root -> t == 0){
        H[a].dead = st;
        return;
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    nw.root = new node();
    nw.Damage = 0;
    nw.R = 1;

    build(nw.root, 1, M);

    H.p_b(nw);

    for(st = 1; st <= q; st++){
        ll t;
        cin >> t;
        if(t == 1){
            H.p_b(H[0]);
        }else if(t == 2){
            ll x;
            cin >> x;
            H[x].Damage++;
        }else if(t == 3){
            ll x;
            cin >> x;
            H[x].R++;
        }else if(t == 4){
            ll pos;
            cin >> pos;
            H.p_b(H[pos]);
            if(H[pos].dead != -1){
                H.back().dead = st;
            }
        }else{
            ll a, b;
            cin >> a >> b;
            if(H[a].dead != -1 || H[b].dead != -1)continue;
            Dec_Hp(a, H[b].Damage);
            Dec_Hp(b, H[a].Damage);
        }
    }

    cout << H.size() - 1 << "\n";

    for(int i = 1; i < H.size(); i++)cout << H[i].dead << " ";
    cout << "\n";

    return 0;
}