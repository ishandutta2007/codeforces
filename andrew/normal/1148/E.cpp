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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <pll> s(n);
    vector <ll> delta(n), t(n);

    for(int i = 0; i < n; i++)cin >> s[i].fi;
    for(int i = 0; i < n; i++)s[i].se = i;
    for(int i = 0; i < n; i++)cin >> t[i];

    sort(all(s));
    sort(all(t));

    for(int i = 0; i < n; i++)delta[i] = t[i] - s[i].fi;

    vector <pair <pll, ll>> ans;

    vector <pll> v;

    for(int i = 0; i < n; i++){
        if(delta[i] > 0){
            v.p_b({s[i].se, delta[i]});
        }else if(delta[i] < 0){
            ll x = -delta[i];
            while(x){
                if(v.empty())vout("NO");
                pll xe = v.back();
                v.pop_back();
                ll k = min(xe.se, x);
                ans.p_b({{xe.fi, s[i].se}, k});
                x -= k;
                xe.se -= k;
                if(xe.se)v.p_b(xe);
            }

        }
    }


    if(!v.empty())vout("NO");
    cout << "YES\n";
    cout << ans.size() << "\n";

    for(auto i : ans)cout << i.fi.fi + 1 << " " << i.fi.se + 1 << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}