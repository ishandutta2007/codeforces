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

vector <ll> v[MAXN], v1[MAXN];

ll t[MAXN];

vector <ll> a;

void build(ll v, ll tl, ll tr){
    if(tl == tr)t[v] = a[tl]; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        t[v] = t[v << 1] & t[(v << 1) + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return pw(32) - 1;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm)) & get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n, m;
    cin >> n >> m;
    a.resize(n + 1);

    vector < pair <pll, ll> > c(m + 1);

    for(int i = 1; i <= m; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        v[l].p_b(x);
        v1[r + 1].p_b(x);
        c[i] = {{l, r}, x};
    }

    for(int i = 0; i < 30; i++){
        ll kol0, kol1;
        kol0 = kol1 = 0;
        for(int j = 1; j <= n; j++){
            for(auto k : v[j]){
                if((k & pw(i)))kol1++; else kol0++;
            }
            for(auto k : v1[j]){
                if((k & pw(i)))kol1--; else kol0--;
            }
            if(kol1)a[j] |= pw(i);
        }
    }

    build(1, 1, n);

    for(int i = 1; i <= m; i++)if(get(1, 1, n, c[i].fi.fi, c[i].fi.se) != c[i].se)vout("NO");

    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << a[i] << " ";
    cout << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}