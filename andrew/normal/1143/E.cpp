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
typedef long double ld;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll f(ll x){
    ll pr = 1;

    while(x){
        pr *= x % 10;
        x /= 10;
    }
    return pr;

}

ll varr[MAXN];

vector <pll> v[MAXN];
vector <ll> c[MAXN];
vector <ll> d[MAXN];

ll t[MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr)t[v] = varr[tl]; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        t[v] = min(t[v << 1], t[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, q;
    cin >> n >> m >> q;

    vector <ll> p(n + 1), wh(n + 1), last(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        wh[p[i]] = i;
        last[i] = 1e18;
    }

    vector <ll> a(m + 1);

    for(int i = 1; i <= m; i++)cin >> a[i];
    for(int i = 1; i <= m; i++)varr[i] = 1e18;
    for(int i = m; i > 0; i--){
        ll x = wh[a[i]];
        if(x == n){
            last[x] = i;
        }else{
            last[x] = last[x + 1];
        }


        if(last[x] != 1e18){
            v[x].p_b({last[x], i});
            if(x == 1)varr[i] = last[x];
        }

    }

    for(int i = 1; i <= n; i++){
        ll mn = -1e18;
        sort(all(v[i]));
        for(auto j : v[i]){
            mn = max(mn, j.se);
            c[i].p_b(mn);
            d[i].p_b(j.fi);
        }
    }

    for(int i = 1; i <= n; i++)last[i] = 1e18;

    for(int i = 1; i <= m; i++){
        ll x = wh[a[i]];
        if(x == 1){
            last[x] = i;
        }else{
            last[x] = last[x - 1];
        }


        if(x < n && last[x] != 1e18 && d[x + 1].size()){
            ll poz = lower_bound(all(d[x + 1]), last[x]) - d[x + 1].begin() - 1;
            if(poz > -1){
                varr[c[x + 1][poz]] = min(varr[c[x + 1][poz]], ll(i));
            }

        }

    }
    build(1, 1, m);
    string ans;
    while(q--){
        ll l, r;
        cin >> l >> r;
        if(get(1, 1, m, l, r) <= r)ans += "1"; else ans += "0";
    }

    cout << ans << "\n";

    cerr << "time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}