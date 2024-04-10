#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}




int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        map <ll, ll> mp;

        ll n;
        cin >> n;
        while(n--){
            ll x;
            cin >> x;
            mp[x]++;
        }

        ll ans = 0;

        vector <ll> c;
        for(auto i : mp)c.p_b(i.se);

        sort(all(c));
        reverse(all(c));

        ll R = 1e18;

        for(auto i : c){
            R = min(R, i);
            if(!R)break;
            ans += R;
            R--;
        }

        cout << ans << "\n";

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}