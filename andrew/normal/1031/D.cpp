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
mt19937_64 gen;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[2011][2011];
char a[2011][2011];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)dp[i][j] = 1e18;

    dp[1][1] = (a[1][1] != 'a');

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)if(i != 1 || j != 1){
        if(i != 1)dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i][j] != 'a'));
        if(j != 1)dp[i][j] = min(dp[i][j], dp[i][j - 1] + (a[i][j] != 'a'));
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)if(dp[i][j] <= k){
        ans = max(ans, ll(i + j - 1));
    }

    string res;

    set <pll> S;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)if(dp[i][j] <= k && i + j - 1 == ans){
        S.insert({i, j});
    }

    for(int i = 1; i <= ans; i++)res += "a";

    if(S.empty()){
        res += a[1][1];
        S.insert({1, 1});
    }

    while(res.size() < 2 * n - 1){
        vector <pll> c;
        for(auto i : S)c.p_b(i);
        S.clear();
        char mn = 'z' + 1;
        for(auto i : c){
            if(i.fi < n)mn = min(mn, a[i.fi + 1][i.se]);
            if(i.se < n)mn = min(mn, a[i.fi][i.se + 1]);
        }

        for(auto i : c){
            if(i.fi < n && a[i.fi + 1][i.se] == mn)S.insert({i.fi + 1, i.se});
            if(i.se < n && a[i.fi][i.se + 1] == mn)S.insert({i.fi, i.se + 1});
        }

        res += mn;

    }

    cout << res << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}