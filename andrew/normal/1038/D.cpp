#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

ll p[3 * MAXN], p1[3 * MAXN], a[MAXN], pref[MAXN], n;

void build(ll v,ll tl, ll tr){
    if(tl == tr){p[v] = a[tl];p1[v] = a[tl];} else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        p[v] = min(p[v << 1], p[(v << 1) + 1]);
        p1[v] = p1[v << 1] + p1[(v << 1) + 1];
    }
}

void modify(ll v,ll tl, ll tr, ll pos, ll val){
    if(tl == tr){p[v] = 1e18;p1[v] = 0;} else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = min(p[v << 1], p[(v << 1) + 1]);
        p1[v] = p1[v << 1] + p1[(v << 1) + 1];
    }
}

pll get(ll v, ll tl, ll tr, ll mn, ll sc){
    if(tl == tr)return {ll(tl), min(mn, p[v])};
    ll tm = (tl + tr) >> 1;
    ll mn1 = min(mn, p[v << 1]);
    ll sm1 = sc + p1[v << 1];

    if(mn1 - (sm1 - mn1) < 0)return get(v << 1, tl, tm, mn, sc); else return get((v << 1) + 1, tm + 1, tr, mn1, sm1);

}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++)cin >> a[i];
    if(n == 1)vout(a[1]);
    for(int i = 1; i <= n; i++)ans += abs(a[i]);
    bool fl = 0;
    for(int i = 1; i <= n; i++)if(a[i] >= 0)fl = 1;
    if(fl)for(int i = 1; i <= n; i++)if(a[i] <= 0)vout(ans);
    if(!fl){
                ll kek = -1e18;
        for(int i = 1; i <= n; i++){
            kek = max(kek, a[i] + ans - abs(a[i]));
        }
        vout(kek);
    }
    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i];
    build(1, 1, n);
    ll kek = -1e18;
    multiset <ll> s;
    ll sc = 0;
    for(int i = 1; i <= n; i++){
        s.insert(a[i]);
        sc += a[i];
    }
    for(int i = 1; i <= n; i++){
        ll _end = *(s.begin());
        if(_end - (sc - _end) > 0)break;
        s.erase(s.find(a[i]));
        sc -= a[i];
        pll xe = get(1, 1, n, 1e18, 0ll);
        ll l = xe.fi, mn = xe.se;
        //cout << l << " " << mn << endl;
        ll sm = pref[l] - pref[i - 1];
        kek = max(kek, ans - sm + abs(mn - (sm - mn)));
        modify(1, 1, n, i, 0);
    }
    if(kek == -1e18)vout(0);
    cout << kek << endl;
    return 0;
}