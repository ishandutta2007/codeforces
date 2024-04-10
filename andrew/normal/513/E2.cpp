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


ll dp[30005][202][4], val[3];
bool f[30005][202][4];

void u(ll &a, ll b){
    a = max(a, b);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    val[0] = 1;
    val[1] = -1;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
        for(int i1 = 0; i1 < 4; i1++)dp[i][j][i1] = -1e18;

    f[0][0][2] = 1;
    f[0][0][3] = 1;
    dp[0][0][2] = 0;
    dp[0][0][3] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int i1 = 0; i1 < 4; i1++)if(f[i][j][i1]){
                if(1 < i1){
                    u(dp[i + 1][j][i1], dp[i][j][i1]);
                    f[i + 1][j][i1] = 1;

                    if(j > 0 && j < k - 1){
                        u(dp[i + 1][j + 1][i1], dp[i][j][i1]);
                        f[i + 1][j + 1][i1] = 1;
                    }

                    ll to = i1 - 2, sc = a[i + 1] * val[to];
                    if(j && j < k - 1)sc *= 2;

                    u(dp[i + 1][j + 1][to], dp[i][j][i1] + sc);
                    f[i + 1][j + 1][to] = 1;
                }else{
                    u(dp[i + 1][j][1 - i1 + 2], dp[i][j][i1]);
                    f[i + 1][j][1 - i1 + 2] = 1;

                    if(j < k - 1){
                        u(dp[i + 1][j + 1][1 - i1 + 2], dp[i][j][i1]);
                        f[i + 1][j + 1][1 - i1 + 2] = 1;
                    }

                    ll sc = a[i + 1] * val[i1];
                    if(j > 1 && j < k)sc *= 2;
                    u(dp[i + 1][j][i1], dp[i][j][i1] + sc);
                    f[i + 1][j][i1] = 1;

                    sc = a[i + 1] * val[1 - i1];
                    if(j < k - 1)sc *= 2;
                    u(dp[i + 1][j + 1][1 - i1], dp[i][j][i1] + sc);
                    f[i + 1][j + 1][1 - i1] = 1;
                }
            }
        }
    }


    ll ans = *max_element(dp[n][k], dp[n][k] + 4);

    cout << ans << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
/*
0 2 - "+"
1 3 - "-"
*/