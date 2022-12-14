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
const ll MOD = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[21][1200][2];
ll sum[21][1200][2];

ll mult(ll a, ll b){
    return (a * b) % MOD;
}

void u(ll &a, ll b){a = (a + b) % MOD;}

ll calc(ll what, ll k){
    if(!what)return 0;
    vector <ll> a;
    ll x = what;

    while(x){
        a.p_b(x % 10);
        x /= 10;
    }
    reverse(all(a));

    ll n = a.size();
    ll ans = 0;

    for(int i = 0; i < 21; i++)
    for(int j = 0; j < 1200; j++){
        dp[i][j][0] = dp[i][j][1] = 0;
        sum[i][j][0] = sum[i][j][1] = 0;
    }

    for(int i = 0; i < 10; i++){
        if(i < a[0]){
            dp[1][pw(i)][0] = 1;
            sum[1][pw(i)][0] = i;
        }else if(i == a[0]){
            dp[1][pw(i)][1] = 1;
            sum[1][pw(i)][1] = i;
        }
    }

    for(int i = 1; i < n; i++){
        for(int old_musk = 0; old_musk < 1200; old_musk++){
            for(int digit = 0; digit < 10; digit++){

                ll Old_musk = old_musk;

                if(Old_musk == 1)Old_musk = 0;//check that all digits before was null
                ll new_musk = pw(digit) | Old_musk;

                u(dp[i + 1][new_musk][0], dp[i][old_musk][0]);
                u(sum[i + 1][new_musk][0], mult(sum[i][old_musk][0], 10ll) + mult(digit, dp[i][old_musk][0]));

                if(digit < a[i]){
                    u(dp[i + 1][new_musk][0], dp[i][old_musk][1]);
                    u(sum[i + 1][new_musk][0], mult(sum[i][old_musk][1], 10ll) + mult(digit, dp[i][old_musk][1]));
                }else if(digit == a[i]){
                    u(dp[i + 1][new_musk][1], dp[i][old_musk][1]);
                    u(sum[i + 1][new_musk][1], mult(sum[i][old_musk][1], 10ll) + mult(digit, dp[i][old_musk][1]));
                }

            }
        }
    }

    for(int i = 1; i < 1200; i++){
        if(__builtin_popcount(i) <= k)u(ans, sum[n][i][0] + sum[n][i][1]);
    }

    return ans;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll l, r, k;
    cin >> l >> r >> k;
    ll res = calc(r, k) - calc(l - 1, k);
    while(res < 0)res += MOD;
    cout << res << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}