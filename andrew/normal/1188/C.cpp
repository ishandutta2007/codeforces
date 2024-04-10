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
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[1011][1011], dp1[1011][1011], S[1011], f[MAXN];

ll val;

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll add(ll a, ll b){
    val = a + b;
    if(val >= mod)val -= mod;
    return val;
}

ll dec(ll a, ll b){
    ll val = a - b;
    if(val < 0)val += mod;
    return val;
}

ll n, k;
vector <ll> a;

ll sol(ll x){
    for(int i = 1; i <= n; i++){
        S[i] = 0;
        for(int j = 1; j <= k; j++)dp[i][j] = dp1[i][j] = 0;
    }

    S[0] = 1;

    ll uk = 1;

    for(int i = 1; i <= n; i++){
        while(uk <= n && a[uk] - a[i] < x)uk++;
        for(int j = 1; j <= k; j++){
            S[j] = add(S[j], dp1[i][j]);
            dp[i][j] = add(dp[i - 1][j], S[j - 1]);
            dp1[uk][j] = add(dp1[uk][j], S[j - 1]);
        }
    }

    return dp[n][k];

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    sort(a.begin() + 1, a.end());

    for(int i = 1; i * (k - 1) <= a[n]; i++){
        f[i] = sol(i);
    }

    ll ans = 0;

    for(int i = 1; i * (k - 1) <= a[n]; i++){
        (ans += mul(i, dec(f[i], f[i + 1]))) %= mod;
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}