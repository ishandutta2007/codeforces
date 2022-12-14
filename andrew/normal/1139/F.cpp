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
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

const ll mod = 1e9 + 7;

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

const ll N = 1e5 + 10;

ordered_set <pll> T[N + 20];

ll con = 0;

void u(ll pos, ll x){
    for(int i = pos; i <= N; i += i & -i)T[i].insert({x, ++con});
}

ll f(ll pos, ll x){
    ll res = 0;
    pll kek = m_p(x, 0);
    for(int i = pos; i > 0; i -= i & -i){
        res += T[i].size() - (T[i].order_of_key(kek));
    }
    return res;
}

ll ans[MAXN];
vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    vector < pair <ll, pll> > a(n);
    for(int i = 0; i < n; i++)cin >> a[i].se.fi;
    for(int i = 0; i < n; i++)cin >> a[i].se.se;
    for(int i = 0; i < n; i++)cin >> a[i].fi;

    vector <pll> b(m);

    for(int i = 0; i < m; i++)cin >> b[i].fi;
    for(int i = 0; i < m; i++)cin >> b[i].se;

    vector <ll> c, d(n);

    for(int i = 0; i < n; i++)c.p_b(a[i].fi);
    for(int i = 0; i < n; i++)d[i] = -a[i].fi + a[i].se.fi;

    sort(all(c));
    sort(all(d));
    sort(all(a));

    //cod1


    for(int i = 0; i < m; i++){
        ll pos = upper_bound(all(c), b[i].se) - c.begin();
        if(pos > 0){
            v[pos - 1].p_b(i);
        }
    }

    for(int i = 0; i < n; i++){
        ll val = -a[i].fi + a[i].se.fi;
        ll pz = lower_bound(all(d), val) - d.begin() + 1;
        u(pz, a[i].se.se);
        for(auto j : v[i]){
            val = b[j].fi - b[j].se;
            pz = upper_bound(all(d), val) - d.begin();
            if(pz)ans[j] += f(pz, b[j].fi);
        }
    }

    //cod2

    for(int i = 0; i <= N; i++)T[i].clear();

    for(int i = 0; i < n; i++)d[i] = a[i].fi + a[i].se.fi;
    sort(all(d));

    for(int i = 0; i < n; i++)v[i].clear();

    for(int i = 0; i < m; i++){
        ll pos = upper_bound(all(c), b[i].se) - c.begin();
        if(pos < n){
            v[pos].p_b(i);
        }
    }

    for(int i = n - 1; i >= 0; i--){
        ll val = a[i].fi + a[i].se.fi;
        ll pz = lower_bound(all(d), val) - d.begin() + 1;
        u(pz, a[i].se.se);
        for(auto j : v[i]){
            val = b[j].fi + b[j].se;
            pz = upper_bound(all(d), val) - d.begin();
            if(pz)ans[j] += f(pz, b[j].fi);
        }
    }

    for(int i = 0; i < m; i++)cout << ans[i] << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}