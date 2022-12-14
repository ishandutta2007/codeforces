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

ll dp[MAXN][2], us[MAXN][2];

bool f[MAXN][2];

vector <ll> a, v[MAXN];

set <ll> ans;

void dfs(ll x, ll pr){
    bool is_leaf = 1;
    dp[x][0] = dp[x][1] = inf;

    for(auto to : v[x])if(to != pr){
        dfs(to, x);
        is_leaf = 0;
    }

    if(is_leaf){
        dp[x][1] = 0;
        dp[x][0] = a[x];
    }else{
        dp[x][1] = dp[x][0] = inf;
        ll sc = 0;
        for(auto to : v[x])if(to != pr){
            sc += dp[to][0];
        }
        dp[x][1] = sc;
        dp[x][0] = sc;

        for(auto to : v[x])if(to != pr){
            dp[x][1] = min(dp[x][1], sc - dp[to][0] + dp[to][1]);
            dp[x][0] = min(dp[x][0], sc - dp[to][0] + dp[to][1] + a[x]);
        }
    }
}

void go(ll x, ll pr){
    bool is_leaf = 1;

    for(auto to : v[x])if(to != pr)is_leaf = 0;

    if(is_leaf){
        if(f[x][0])ans.insert(x);
    }else{
        ll sc = 0;
        for(auto to : v[x])if(to != pr){
            sc += dp[to][0];
        }

        ll kola, kolb, wha, whb;
        wha = whb = kola = kolb = 0;

        if(f[x][0] && dp[x][0] == sc){
            for(auto to : v[x])if(to != pr)f[to][0] = 1;
        }

        if(f[x][1] && dp[x][1] == sc){
            for(auto to : v[x])if(to != pr)f[to][0] = 1;
        }

        for(auto to : v[x])if(to != pr){
            if(f[x][1] && dp[x][1] == sc - dp[to][0] + dp[to][1]){
                kolb++;
                whb = to;
            }
            if(f[x][0] && dp[x][0] == sc - dp[to][0] + dp[to][1] + a[x]){
                ans.insert(x);
                kola++;
                wha = to;
            }
        }

        if(f[x][0]){
            for(auto to : v[x])if(to != pr){
                if(kola == 1 && wha == to)f[to][1] = 1;
                else f[to][0] = 1;
            }
        }

        if(f[x][1]){
            for(auto to : v[x])if(to != pr){
                if(kolb == 1 && whb == to)f[to][1] = 1;
                else f[to][0] = 1;
            }
        }

        for(auto to : v[x])if(to != pr)go(to, x);

    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll);

    f[1][0] = 1;

    go(1, 0);

    cout << dp[1][0] << " " << ans.size() << "\n";

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    return 0;
}