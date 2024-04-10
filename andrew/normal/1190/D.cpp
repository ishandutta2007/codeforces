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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll f(ll x){
    return x * (x + 1) / 2;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ordered_set <ll> s;

    ll n;
    cin >> n;

    map < ll, vector <ll> > mp;

    while(n--){
        ll x, y;
        cin >> x >> y;
        mp[-y].p_b(x);
    }

    ll ans = 0;

    for(auto i : mp){
        for(auto j : i.se)s.insert(j);
        i.se.p_b(0);
        i.se.p_b(1e9 + 1);
        sort(all(i.se));
        ans += f(s.size());
        for(int j = 1; j < i.se.size(); j++){
            ll l = i.se[j - 1], r = i.se[j];
            if(l < r){
                ans -= f(ll(s.order_of_key(r)) - ll(s.order_of_key(l + 1)));
            }
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}