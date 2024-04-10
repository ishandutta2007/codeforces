#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll kol[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> a(n + 1), b(n + 1);

    map <ll, ll> mp;

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];

    for(int i = 1; i <= n; i++)kol[b[i]] = i;

    ll ans = 1e18;

    ll sc = 0;

    for(int i = 1; i <= n; i++){
        sc = max(sc, kol[i] - i + 1);
    }

    ans = min(ans, sc + n);

    if(b[n]){
        bool ok = 0;
        for(int i = n; i >= 1; i--){
            if(b[i] == 1){
                ok = 1;
                break;
            }
            if(b[i] - 1 != b[i - 1])break;
        }

        if(ok){
            ll l = b[n] + 1;
            ll sc = 0;
            bool good = 1;
            for(int i = l; i <= n; i++){
                ll v = kol[i];
                if(v > i - l)good = 0;

            }
            if(good)ans = min(ans, n - b[n]);
        }

    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}