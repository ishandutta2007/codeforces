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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

const ll MOD = 998244353;

void u(ll &a, ll b){a = min(a, b);}


ll dp[MAXN][7];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("fence.in","r",stdin);
    //freopen("fence.out","w",stdout);

    string c = "hard";

    ll n;
    cin >> n;

    string a;
    cin >> a;
    a = "*" + a;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 6; j++)dp[i][j] = 1e18;

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 0; j < 4; j++){
            if(a[i] != c[j]){
                u(dp[i][j], dp[i - 1][j]);
            }
            if(a[i] == c[j])u(dp[i][j + 1], dp[i - 1][j]);
            u(dp[i][j], dp[i - 1][j] + x);
        }
    }

    ll ans = 1e18;

    for(int i = 0; i < 4; i++)u(ans, dp[n][i]);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}