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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[51][51][51][51];

char a[51][51];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)cin >> a[i][j];

    for(int i = n; i > 0; i--){
        for(int j = i; j <= n; j++){
            for(int i1 = n; i1 > 0; i1--){
                for(int j1 = i1; j1 <= n; j1++){
                    if(i == j && i1 == j1){
                        dp[i][j][i1][j1] = (a[i][i1] == '#');
                    }else dp[i][j][i1][j1] = max(j - i + 1, j1 - i1 + 1);

                    for(int mb = i; mb < j; mb++)dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][mb][i1][j1] + dp[mb + 1][j][i1][j1]);
                    for(int mb = i1; mb < j1; mb++)dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][j][i1][mb] + dp[i][j][mb + 1][j1]);

                }
            }
        }
    }

    cout << dp[1][n][1][n] << "\n";

    return 0;
}