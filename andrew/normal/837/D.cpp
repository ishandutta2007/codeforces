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
const ll N = 2e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int dp[2][202][5429];
bool f[2][202][5429];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector <int> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        while(x % 2 == 0){
            a[i]++;
            x /= 2;
        }
        while(x % 5 == 0){
            b[i]++;
            x /= 5;
        }
    }

    f[0][0][0] = 1;

    ll old = 0;

    for(int i = 0; i < n; i++){
        ll _new = 1 - old;
        for(int j = 0; j <= k; j++)
        for(int i1 = 0; i1 < 5429; i1++)if(f[old][j][i1]){
            f[_new][j][i1] = 1;
            dp[_new][j][i1] = max(dp[_new][j][i1], dp[old][j][i1]);
            if(j < k){
                f[_new][j + 1][i1 + b[i + 1]] = 1;
                dp[_new][j + 1][i1 + b[i + 1]] = max(dp[_new][j + 1][i1 + b[i + 1]], dp[old][j][i1] + a[i + 1]);
            }
        }

        for(int j = 0; j <= k; j++)
        for(int i1 = 0; i1 < 5429; i1++){
            f[old][j][i1] = 0;
            dp[old][j][i1] = 0;
        }
        old = _new;
    }

    int ans = 0;

    for(int i = 0; i < 5429; i++)if(f[old][k][i])ans = max(ans, min(i, dp[old][k][i]));

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
/*
26
*/