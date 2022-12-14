#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define hash sosat

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll mod = 42;
const ll mod1 = 998244353;

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
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll bp1(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod1;
        (a *= a) %= mod1;
        n >>= 1;
    }
    return res;
}

ll dp[MAXN][2], pr[MAXN][2];

bool f[MAXN][2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 0; i <= n + 1; i++){
        dp[i][0] = -1e18;
        dp[i][1] = 1e18;
    }

    f[1][0] = f[1][1] = 1;

    dp[1][0] = 1e18;
    dp[1][1] = -1e18;

    for(int i = 2; i <= n; i++){
        for(int old = 0; old < 2; old++)if(f[i - 1][old]){
            ll l, l1;
            if(!old)l = a[i - 1], l1 = dp[i - 1][old]; else l1 = a[i - 1], l = dp[i - 1][old];

            if(a[i] > l){
                f[i][0] = 1;
                dp[i][0] = max(l1, dp[i][0]);
                if(dp[i][0] == l1){
                    pr[i][0] = old;
                }
            }

            if(a[i] < l1){
                f[i][1] = 1;
                dp[i][1] = min(l, dp[i][1]);

                if(dp[i][1] == l){
                    pr[i][1] = old;
                }
            }

        }
    }

    ll what = -1;

    for(int i = 0; i < 2; i++)if(f[n][i])what = i;

    if(what == -1)vout("NO");
    cout << "YES\n";

    vector <ll> ans(n);

    for(int i = n; i > 0; i--){
        ans[i - 1] = what;
        what = pr[i][what];
    }

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}