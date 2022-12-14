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
const ll MOD = 1e9 + 7;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll DP[51][51][51];

ll f[52][52][52][3];

vector < vector <vector <ll> > > dp[2501];

vector <ll> a, b, c;

ll fact[MAXN];

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    f[0][0][1][2] = 1;
    f[0][1][0][1] = 1;
    f[1][0][0][0] = 1;

    fact[0] = 1;

    for(ll i = 1; i <= 100; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++)
        for(int i1 = 0; i1 <= 50; i1++){

            (f[i][j][i1 + 1][2] += f[i][j][i1][0]) %= MOD;
            (f[i][j][i1 + 1][2] += f[i][j][i1][1]) %= MOD;

            (f[i][j + 1][i1][1] += f[i][j][i1][0]) %= MOD;
            (f[i][j + 1][i1][1] += f[i][j][i1][2]) %= MOD;

            (f[i + 1][j][i1][0] += f[i][j][i1][1]) %= MOD;
            (f[i + 1][j][i1][0] += f[i][j][i1][2]) %= MOD;

            (DP[i][j][i1] += f[i][j][i1][0]) %= MOD;
            (DP[i][j][i1] += f[i][j][i1][1]) %= MOD;
            (DP[i][j][i1] += f[i][j][i1][2]) %= MOD;

        }

    while(n--){
        ll t, g;
        cin >> t >> g;
        if(g == 1)a.p_b(t);
        else if(g == 2)b.p_b(t);
        else if(g == 3)c.p_b(t);
    }


    for(int i = 0; i <= 2500; i++){
        dp[i].resize(a.size() + 1);

        for(int j = 0; j < a.size() + 1; j++){
            dp[i][j].resize(b.size() + 1);
            for(int i1 = 0; i1 < b.size() + 1; i1++)dp[i][j][i1].resize(c.size() + 1);
        }
    }

    dp[0][0][0][0] = 1;

    for(auto kek : a){
        for(int i = m - kek; i >= 0; i--){
            for(int ra = 0; ra <= a.size(); ra++)
                for(int rb = 0; rb <= b.size(); rb++)
            for(int rc = 0; rc <= c.size(); rc++)if(dp[i][ra][rb][rc]){
                (dp[i + kek][ra + 1][rb][rc] += dp[i][ra][rb][rc]) %= MOD;
            }
        }
    }

    for(auto kek : b){
        for(int i = m - kek; i >= 0; i--){
            for(int ra = 0; ra <= a.size(); ra++)
                for(int rb = 0; rb <= b.size(); rb++)
            for(int rc = 0; rc <= c.size(); rc++)if(dp[i][ra][rb][rc]){
                (dp[i + kek][ra][rb + 1][rc] += dp[i][ra][rb][rc]) %= MOD;
            }
        }
    }

    for(auto kek : c){
        for(int i = m - kek; i >= 0; i--){
            for(int ra = 0; ra <= a.size(); ra++)
                for(int rb = 0; rb <= b.size(); rb++)
            for(int rc = 0; rc <= c.size(); rc++)if(dp[i][ra][rb][rc]){
                (dp[i + kek][ra][rb][rc + 1] += dp[i][ra][rb][rc]) %= MOD;
            }
        }
    }

    ll ans = 0;

        for(int ra = 0; ra <= a.size(); ra++)
        for(int rb = 0; rb <= b.size(); rb++)
    for(int rc = 0; rc <= c.size(); rc++){
        (ans += mul(dp[m][ra][rb][rc], mul(DP[ra][rb][rc], mul(fact[ra], mul(fact[rb], fact[rc]))))) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}