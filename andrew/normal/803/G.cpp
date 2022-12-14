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
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
ll N;
mt19937_64 gen;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

struct node{
    int t, t1, le, ri;
    bool f;
    node *l, *r;
    node() : le(-1), ri(-1), f(0), t(1e9), t1(-1), l(r=nullptr){}
};

int sp[200000][18], st[MAXN];

int f(int l, int r){
    return min(sp[l][st[r - l + 1]], sp[r - pw(st[r - l + 1]) + 1][st[r - l + 1]]);
}

node *root = new node();

void push(node *v){
    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();
    (v -> l) -> t = v -> t1;
    (v -> r) -> t = v -> t1;
    (v -> l) -> t1 = v -> t1;
    (v -> r) -> t1 = v -> t1;
    (v -> l) -> f = 1;
    (v -> r) -> f = 1;
    (v -> l) -> f = 0;
    (v -> r) -> f = 0;
    v -> t1 = -1;
}

int Val(node *v){
    if(v == nullptr)return 1e9;
    return v -> t;
}

ll L;

void MEGA_PUSH(node *v, int tl, int tr){
    int tm = (tl + tr) >> 1;
    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();
    (v -> l) -> le = v -> le;
    (v -> l) -> ri = v -> le + tm - tl;
    (v -> r) -> le = v -> le + tm - tl + 1;
    (v -> r) -> ri = v -> ri;
    (v -> l) -> t = f((v -> l) -> le, (v -> l) -> ri);
    (v -> r) -> t = f((v -> r) -> le, (v -> r) -> ri);
    (v -> l) -> f = 1;
    (v -> r) -> f = 1;
    v -> f = 0;
    return;
}

int get(node *v, int tl, int tr, int l, int r){
    if(v == nullptr)return 1e9;
    if(l > r)return 1e9;
    if(tl == l && tr == r){
        return v -> t;
    }
    int tm = (tl + tr) >> 1;
    if(v -> t1 != -1)push(v);
    if(v -> f == 1)MEGA_PUSH(v, tl, tr);
    return min(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

void update(node *v, int tl, int tr, int l, int r){
    if(l > r)return;

    if(tl == l && tr == r){
        v -> le = l - L + 1;
        v -> ri = r - L + 1;
        v -> t = f(v -> le, v -> ri);
        v -> f = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();
    update(v -> l, tl, tm, l, min(r, tm));
    update(v -> r, tm + 1, tr, max(l, tm + 1), r);
    v -> t = min(Val(v -> l), Val(v -> r));
}

void modify(node *v, int tl, int tr, int l, int r, int val){
    if(l > r)return;
    if(tl == l && tr == r){
        v -> t = val;
        v -> t1 = val;
        v -> f = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(v -> t1 != -1)push(v);
    if(v -> f == 1)MEGA_PUSH(v, tl, tr);

    if(v -> l == nullptr)v -> l = new node();
    if(v -> r == nullptr)v -> r = new node();

    modify(v -> l, tl, tm, l, min(r, tm), val);
    modify(v -> r, tm + 1, tr, max(l, tm + 1), r, val);
    v -> t = min(Val(v -> l), Val(v -> r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    N = n * k;

    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++)cin >> b[i];

    for(int i = 1; i <= n; i++)sp[i][0] = b[i];

    for(int j = 1; j < 18; j++){
        for(int i = 1; i <= n; i++)sp[i][j] = min(sp[i][j - 1], sp[i + pw(j - 1)][j - 1]);
    }

    ll kek = 0;

    for(int i = 1; i < MAXN; i++){
        while(pw(kek + 1) < i)kek++;
        st[i] = kek;
    }


    int l = 1;

    for(int i = 1; i <= k; i++){
        L = l;
        update(root, 1, N, l, l + n - 1);
        l += n;
    }


    int q;
    cin >> q;

    while(q--){
        int l, r, t;
        cin >> t >> l >> r;
        if(t == 1){
            int val;
            cin >> val;
            modify(root, 1, N, l, r, val);
        }else{
            cout << get(root, 1, N, l, r) << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}