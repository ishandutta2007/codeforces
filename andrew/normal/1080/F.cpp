#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ple pair<pll, ll>

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;


template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll root[MAXN];

struct vertex{
    ll l, r, p = -1e18;
};

vertex _new;

vector <vertex> T;

void build(ll v, ll tl, ll tr){
    T.p_b(_new);
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        T[v].l = T.size();
        build(T[v].l, tl, tm);
        T[v].r = T.size();
        build(T[v].r, tm + 1, tr);
    }
}

void modify(ll old, ll v, ll tl, ll tr, ll pos, ll val){
    T.p_b(_new);
    if(tl == tr)T[v].p = max(T[old].p, val); else{
        ll tm = (tl + tr) >> 1;
        T[v].l = T[old].l;
        T[v].r = T[old].r;
        if(pos <= tm){
            ll _new = T.size();
            modify(T[v].l, T.size(), tl, tm, pos, val);
            T[v].l = _new;
        }else{
            ll _new = T.size();
            modify(T[v].r, T.size(), tm + 1, tr, pos, val);
            T[v].r = _new;
        }
        T[v].p = min(T[T[v].l].p, T[T[v].r].p);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return T[v].p;
    ll tm = (tl + tr) >> 1;
    return min(get(T[v].l, tl, tm, l, min(r, tm)), get(T[v].r, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> k >> m;

    vector <ple> a(m);
    vector <ll> fu(m);

    for(int i = 0; i < m; i++){
        cin >> a[i].fi.se >> a[i].fi.fi >> a[i].se;
        fu[i] = a[i].fi.fi;
    }

    root[0] = 0;
    sort(all(a));
    sort(all(fu));
    build(0, 1, n);

    multiset <ple> s;

    for(int i = 0; i < m; i++){
        ll l = a[i].fi.se, r = a[i].fi.fi;
        ll kek = root[i];
        ll old = kek;
        kek = T.size();
        modify(old, kek, 1, n, a[i].se, l);

        root[i + 1] = kek;
    }

    while(k--){
        ll aa, b, x, y;
        cin >> aa >> b >> x >> y;

        ll r = upper_bound(all(fu), y) - fu.begin();

        string ans = "no";
        if(r != 0){
            if(a[r - 1].fi.fi >= x){
                ll val = get(root[r], 1, n, aa, b);
                if(val >= x)ans = "yes";
            }
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}