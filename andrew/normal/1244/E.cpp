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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> pref, pref1;

ll get(ll l, ll r){
    return pref[r] - (l ? pref[l - 1] : 0);
}

ll get1(ll l, ll r){
    return pref1[r] - (l ? pref1[l - 1] : 0);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    sort(a.begin() + 1, a.end());

    map <ll, ll> mp;

    for(int i = 1; i <= n; i++)mp[a[i]]++;
    vector <ll> b;
    b.p_b(0ll);
    for(auto i : mp)b.p_b(i.fi);

    ll m = b.size() - 1;

    pref.resize(n + 2);
    pref1.resize(n + 2);

    for(int i = 1; i <= m; i++){
        pref[i] = pref[i - 1] + b[i] * mp[b[i]];
        pref1[i] = pref1[i - 1] + mp[b[i]];
    }

    vector <pair<pll, ll> > huk;

    ll ans = a[n] - a[1];

    ll kol = 0, last = 0;

    for(auto i : mp){
        if(!last){
            kol = i.se;
            last = i.fi;
        }else{
            huk.p_b({{kol, -(i.fi - last)}, 0});
            kol += i.se;
            last = i.fi;
        }
    }

    map <ll, ll> :: iterator it = mp.end();

    kol = 0;
    last = 0;

    for(; it != mp.begin(); ){
        --it;
        if(!last){
            kol = it -> se;
            last = it -> fi;
        }else{
            huk.p_b({{kol, -(last - it -> fi)}, 1});
            kol += it -> se;
            last = it -> fi;
        }
    }

    sort(all(huk));
    ll L = a[1], R = a[n];

    for(auto kek : huk){
        ll cost = kek.fi.fi, len = kek.fi.se, wh = kek.se;

        ll can = min(k / cost, -len);

        k -= can * cost;

        if(!wh){
            L += can;
        }else{
            R -= can;
        }

    }

    cout << max(0ll, R - L) << "\n";

    return 0;
}