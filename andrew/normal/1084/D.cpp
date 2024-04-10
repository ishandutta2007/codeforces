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

ll ans = 0;

vector <pll> v[MAXN];

ll w[MAXN], dp[MAXN][2];

void dfs(ll x, ll pr = 0){
    vector <ll> c;

    for(auto to : v[x])if(to.fi != pr){
        dfs(to.fi, x);
        c.p_b(max(dp[to.fi][0] - to.se, 0ll));
    }

    sort(all(c));
    reverse(all(c));


    dp[x][0] = w[x];

    if(c.size())dp[x][0] += c[0];

    if(c.size() > 1){
        ll sc = w[x];

        for(int i = 0; i < min(2ll, ll(c.size())); i++)sc += c[i];
        ans = max(ans, sc);

    }

    ans = max(ans, dp[x][0]);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++)cin >> w[i];

    ll m = n - 1;

    while(m--){
         ll a, b, c;
         cin >> a >> b >> c;
         v[a].p_b({b, c});
         v[b].p_b({a, c});
    }

    dfs(1ll);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}