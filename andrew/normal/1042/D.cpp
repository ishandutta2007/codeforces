#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

ll p[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p[v] = val; else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify(v << 1 | 1, tm + 1, tr, pos, val);
        p[v] = p[v << 1] + p[v << 1 | 1];
     }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return p[v];
    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), pref(n);
    vector <pll> kek;
    vector <ll> where(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i] = a[i];
        if(i)pref[i] += pref[i - 1];
        kek.p_b(m_p(pref[i], i));
    }
    sort(all(kek));
    for(int i = 0; i < n; i++)where[kek[i].se] = i + 1;
    for(int i = 1; i <= n; i++)modify(1, 1, n, i, 1);
    ll sc = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        pll kkk = m_p(sc + m - 1, 1e18);
        ll l = upper_bound(all(kek), kkk) - kek.begin() + 1;
        l--;
        ans += get(1, 1, n, 1, l);
        modify(1, 1, n, where[i], 0);
        sc += a[i];
    }
    vout(ans);
    return 0;
}