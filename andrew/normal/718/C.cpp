#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

const ll MOD = 1e9 + 7;
ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

struct matrix{
    int n, m;
    vector < vector <ll> > Val;

    void anons(int x, int y){
        n = x;
        m = y;
        Val.resize(n);
        for(int i = 0; i < n; i++)Val[i].resize(m);
    }


};

int i, j, k;

matrix operator + (const matrix &a, const matrix &b){
    matrix res = a;

    for(i = 0; i < res.n; i++)
        for(j = 0; j < res.m; j++){
                res.Val[i][j] += b.Val[i][j];
                if(res.Val[i][j] >= MOD)res.Val[i][j] -= MOD;
        }

    return res;
}


matrix operator * (const matrix &a, const matrix &b){
    matrix res;
    res.anons(a.n, b.m);
    for(i = 0; i < a.n; i++)
        for(j = 0; j < b.m; j++)
        for(k = 0; k < min(a.m, b.n); k++){
            res.Val[i][j] += a.Val[i][k] * b.Val[k][j];
            if(res.Val[i][j] >= MOD)res.Val[i][j] %= MOD;
        }

    return res;
}

matrix MUSOR[40];

matrix operator ^ (const matrix &a, ll k){
    matrix res;
    bool f = 0;
    ll step = 0;
    res.anons(a.n, a.n);

    while(k){
        if(k & 1){
            if(!f){
                f = 1;
                res = MUSOR[step];
            }else res = res * MUSOR[step];
        }
        k >>= 1;
        step++;
    }

    return res;

}

matrix STD;

matrix Vec;

ll f(ll x){
    if(x <= 2)return 1;
    return (Vec * (STD ^ (x - 2))).Val[0][1];
}

matrix old[MAXN];
matrix tk;
matrix t[MAXN], tt[MAXN];
ll t1[MAXN];

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = old[tl];
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        t[v] = t[v << 1] + t[(v << 1) + 1];
    }
}

void push(int v){

    t[v << 1] = t[v << 1] * tt[v];

    if(!t1[v << 1])tt[v << 1] = tt[v]; else
    tt[v << 1] = tt[v << 1] * tt[v];

    t[(v << 1) + 1] = t[(v << 1) + 1] * tt[v];

    if(!t1[(v << 1) + 1])tt[(v << 1) + 1] = tt[v];else
    tt[(v << 1) + 1] = tt[(v << 1) + 1] * tt[v];

    t1[v] = 0;
    t1[v << 1] = 1;
    t1[(v << 1) + 1] = 1;
    return;
}

void modify(int v, int tl, int tr, int l, int r){
    if(l > r)return;
    if(tl == l && tr == r){

        t[v] = t[v] * tk;

        if(!t1[v]){
            tt[v] = tk;
        }else tt[v] = tt[v] * tk;

        t1[v] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    modify(v << 1, tl, tm, l, min(r, tm));
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = t[v << 1] + t[(v << 1) + 1];
}

matrix clr;

matrix get(int v, int tl, int tr, int l, int r){
    if(l > r)return clr;
    if(tl == l && tr == r)return t[v];
    int tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("brackets.in","r",stdin);
    //freopen("brackets.out","w",stdout);

    STD.anons(2, 2);
    STD.Val[0][0] = 0;
    STD.Val[0][1] = 1;
    STD.Val[1][1] = 1;
    STD.Val[1][0] = 1;
    clr.anons(1, 2);
    Vec.anons(1, 2);
    Vec.Val[0][0] = Vec.Val[0][1] = 1;

    ll n, q;
    cin >> n >> q;

    MUSOR[0] = STD;

    for(int i = 1; i < 40; i++)MUSOR[i] = MUSOR[i - 1] * MUSOR[i - 1];

    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        old[i].anons(1, 2);
        old[i].Val[0][0] = 1, old[i].Val[0][1] = 1;
        if(a > 1){
            old[i] = old[i] * (STD ^ (a - 1));
        }
    }

    build(1, 1, n);


    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll l, r, x;
            cin >> l >> r >> x;
            tk = STD ^ x;
            modify(1, 1, n, l, r);
        }else{
            ll l, r;
            cin >> l >> r;
            matrix res = get(1, 1, n, l, r);
            cout << res.Val[0][0] << "\n";
        }
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}