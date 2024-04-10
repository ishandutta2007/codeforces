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
const ll MOD = 1e9 + 7;

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
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

ll ans = 0;

ll dp[MAXN][4];

vector <pll> v[MAXN];

void dfs(ll x, ll pr = 0){

    for(auto to : v[x])if(to.fi != pr){
        dfs(to.fi, x);

        if(!to.se){
            dp[x][0] += dp[to.fi][0] + 1;
            dp[x][2] += dp[to.fi][1];
            dp[x][2] += dp[to.fi][2];
        }else{
            dp[x][1] += dp[to.fi][1] + 1;
            dp[x][3] += dp[to.fi][0];
            dp[x][3] += dp[to.fi][3];

        }
    }


    for(int i = 0; i < 2; i++)ans += 2 * dp[x][i];
    ans += dp[x][2];
    ans += dp[x][3];
    ll ansp = 0;
    for(auto to : v[x])if(to.fi != pr){
        vector <ll> sc(4), d(4);
        for(int i = 0; i < 4; i++)sc[i] = dp[x][i];

        if(!to.se){
            d[0] += dp[to.fi][0] + 1;
            d[2] += dp[to.fi][1];
            d[2] += dp[to.fi][2];

            sc[0] -= dp[to.fi][0] + 1;
            sc[2] -= dp[to.fi][1];
            sc[2] -= dp[to.fi][2];
        }else{
            d[1] += dp[to.fi][1] + 1;
            d[3] += dp[to.fi][0];
            d[3] += dp[to.fi][3];

            sc[1] -= dp[to.fi][1] + 1;
            sc[3] -= dp[to.fi][0];
            sc[3] -= dp[to.fi][3];

        }

        ans += d[0] * sc[0];
        ans += d[0] * sc[1];
        ans += d[0] * sc[2];

        ans += d[1] * sc[1];

        ans += d[3] * sc[1];

    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("twohorse.in","r",stdin);
    //freopen("twohorse.out","w",stdout);

    ll n;
    cin >> n;

    for(int i = 1; i < n; i++){
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