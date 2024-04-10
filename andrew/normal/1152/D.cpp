#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define pll pair<ll, ll>
#define m_p make_pair
#define p_b push_back
#define all(v) v.begin(), v.end()
#define sqr(x)  (x) * (x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e3;
const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll dp[2011][2011];
bool f[2011][2011];

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    dp[0][N] = 1;

    ll ans = 0;

    for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j <= 2 * N; j++)if(j >= N){
            if(j + 1 <= 2 * N)dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            if(j - 1 >= 0)dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
        }
    }

    f[2 * n][N] = 1;

    for(int i = 2 * n; i > 0; i--){
        for(int j = 0; j <= 2 * N; j++)if(j <= N){
            if(j + 1 <= 2 * N)f[i - 1][j + 1] |= f[i][j];
            if(j - 1 >= 0)f[i - 1][j - 1] |= f[i][j];
        }
    }

    for(int i = 1; i < 2 * n; i += 2){
        for(int j = 0; j <= 2 * N; j++)if(j >= N && f[i][2 * N - j]){
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}