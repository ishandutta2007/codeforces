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

int p[9 * 100000 + 2][21], p1[9 * 100000 + 2];

int a[MAXN], n;

void push(int v, int tl, int tr){
    int tm = (tl + tr) >> 1;
    for(int i = 0; i < 21; i++)if((pw(i) & p1[v]))p[v << 1][i] = (tm - tl + 1) - p[v << 1][i];
    for(int i = 0; i < 21; i++)if((pw(i) & p1[v]))p[(v << 1) + 1][i] = (tr - tm) - p[(v << 1) + 1][i];
    p1[v << 1] ^= p1[v];
    p1[(v << 1) + 1] ^= p1[v];
    p1[v] = 0;
}

void build(int v, int tl, int tr){
    if(tl == tr){
        for(int i = 0; i < 21; i++)if((pw(i) & a[tl]))p[v][i]++;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build((v << 1) + 1, tm + 1, tr);
    for(int i = 0; i < 21; i++)p[v][i] = p[v << 1][i] + p[(v << 1) + 1][i];
}

void modify(int v, int tl, int tr, int l, int r, int val){
    if(l > r)return;
    if(tl == l && tr == r){
        for(int i = 0; i < 21; i++)if((val & pw(i)))p[v][i] = tr - tl + 1 - p[v][i];
        p1[v] ^= val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(p1[v])push(v, tl, tr);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    for(int i = 0; i < 21; i++)p[v][i] = p[v << 1][i] + p[(v << 1) + 1][i];
}

ll get(int v, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(tl == l && tr == r){
        ll res = 0;
        for(int i = 0; i < 21; i++)res += pw(i) * p[v][i];
        return res;
    }
    int tm = (tl + tr) >> 1;
    if(p1[v])push(v, tl, tr);
    return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    build(1, 1, n);
    ll q;
    cin >> q;
    while(q--){
        int x, l, r;
        cin >> x >> l >> r;
        if(x == 1)cout << get(1, 1, n, l, r) << "\n"; else {
            int val;
            cin >> val;
            modify(1, 1, n, l, r, val);
        }
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}