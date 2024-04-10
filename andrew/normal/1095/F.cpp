#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector <pll> v[MAXN];

ll p[MAXN], kol[MAXN], mn[MAXN];

ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;

    cin >> n >> m;

    vector <ll> a(n + 1);
    vector <pll> c(n + 1);

    set <pll> mb;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn[i] = a[i];
        mb.insert({a[i], i});
        p[i] = i;
        c[i].fi = a[i];
        c[i].se = i;
    }

    sort(c.begin() + 1, c.end());

    ll val, to;

    val = c[1].fi, to = c[1].se;

    vector <pair <ll, pll> > b(m);

    for(int i = 0; i < m; i++){
        cin >> b[i].se.fi >> b[i].se.se >> b[i].fi;
    }

    for(int i = 2; i <= n; i++)b.p_b({c[i].fi + val, {c[i].se, to}});

    sort(all(b));

    ll ans = 0;

    for(int i = 0; i < b.size(); i++){
        ll ra = get(b[i].se.fi), rb = get(b[i].se.se), val = b[i].fi;
        if(ra != rb){
            ans += val;
            p[ra] = rb;
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}