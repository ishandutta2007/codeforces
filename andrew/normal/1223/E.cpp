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

ll dp[MAXN], dp1[MAXN], k;

vector <pll> v[MAXN];

void dfs(ll x, ll pr){
    ll sc = 0;
    vector <pll> t;
    for(auto to : v[x])if(to.fi != pr){
        dfs(to.fi, x);
        if(dp1[to.fi] + to.se < dp[to.fi]){
            sc += dp[to.fi];
        }else{
            t.p_b({dp1[to.fi] + to.se - dp[to.fi], to.fi});
        }
    }

    sort(all(t));
    reverse(all(t));

    dp[x] = sc;
    dp1[x] = sc;

    for(int i = 0; i < t.size(); i++){
        if(i + 1 < k){
            dp1[x] += t[i].fi + dp[t[i].se];
        }else dp1[x] += dp[t[i].se];

        if(i + 1 <= k){
            dp[x] += t[i].fi + dp[t[i].se];
        }else dp[x] += dp[t[i].se];
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    while(q--){
        ll n;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            dp[i] = dp1[i] = 0;
            v[i].clear();
        }
        for(int i = 1; i < n; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            v[a].p_b({b, c});
            v[b].p_b({a, c});

        }
        dfs(1ll, 0ll);
        cout << max(dp[1], dp1[1]) << "\n";
    }

    return 0;
}