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
    int kol, ColPref[11], ColSuf[11], pPref[11], pSuf[11];
};

int a[11][N], n, m;

int p[41];
int f[41];

int get(int x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

node T[MAXN];

node unite(node l, node r){
    if(!l.kol)return r;
    if(!r.kol)return l;
    node res;
    res.kol = l.kol + r.kol;

    for(int i = 1; i <= 40; i++){
        p[i] = i;
        f[i] = 0;
    }

    for(int i = 1; i <= n; i++)if(l.ColSuf[i] == r.ColPref[i]){
        if(get(l.pSuf[i]) != get(r.pPref[i] + 20)){
            p[get(l.pSuf[i])] = get(r.pPref[i] + 20);
            res.kol--;
        }
    }

    int Kol = 0;

    for(int i = 1; i <= n; i++){
        res.ColPref[i] = l.ColPref[i];
        res.ColSuf[i] = r.ColSuf[i];
        int val = get(l.pPref[i]);
        if(!f[val]){
            Kol++;
            f[val] = Kol;
        }
        res.pPref[i] = f[val];

        val = get(r.pSuf[i] + 20);

        if(!f[val]){
            Kol++;
            f[val] = Kol;
        }

        res.pSuf[i] = f[val];

    }

    return res;

}

void build(int v, int tl, int tr){
    if(tl == tr){
        int Kol = 0;
        for(int i = 1; i <= n; i++){
            if(a[i][tl] != a[i - 1][tl])Kol++;
            T[v].ColPref[i] = T[v].ColSuf[i] = a[i][tl];
            T[v].pPref[i] = T[v].pSuf[i] = Kol;
        }
        T[v].kol = Kol;

    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        T[v] = unite(T[v << 1], T[(v << 1) + 1]);
    }
}

node clr;

node get(int v, int tl, int tr, int l, int r){
    if(l > r)return clr;
    if(tl == l && tr == r)return T[v];
    int tm = (tl + tr) >> 1;
    return unite(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;

    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    }


    build(1, 1, m);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, m, l, r).kol << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}