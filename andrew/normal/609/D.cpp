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

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k, s;
    cin >> n >> m >> k >> s;

    vector <ll> a(n + 1), b(n + 1);

    vector <pll> div(m);

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];

    for(int i = 0; i < m; i++)cin >> div[i].fi >> div[i].se;

    ll l = 1, r = n + 1;

    while(l < r){
        ll c = (l + r) >> 1;
        ll sc = 0;
        vector <ll> d;
        ll mna, mnb;
        mna = mnb = 1e18;

        for(int i = 1; i <= c; i++){
            mna = min(mna, a[i]);
            mnb = min(mnb, b[i]);
        }

        for(int i = 0; i < m; i++){
            if(div[i].fi == 1){
                d.p_b(mna * div[i].se);
            }else d.p_b(mnb * div[i].se);
        }

        sort(all(d));

        for(int i = 0; i < k; i++)sc += d[i];

        d.clear();
        if(sc > s)l = c + 1; else r = c;

    }

    if(r == n + 1)vout(-1);

    cout << l << "\n";

    vector < pair<ll, pll> > d;
    pll mna, mnb;
    mna = mnb = {1e18, 1e18};

    for(int i = 1; i <= l; i++){
        mna = min(mna, {a[i], i});
        mnb = min(mnb, {b[i], i});
    }

    for(int i = 0; i < m; i++){
        if(div[i].fi == 1){
            d.p_b({mna.fi * div[i].se, {i + 1, mna.se}});
        }else d.p_b({mnb.fi * div[i].se, {i + 1, mnb.se}});
    }

    sort(all(d));

    for(int i = 0; i < k; i++){
        cout << d[i].se.fi << " " << d[i].se.se << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}