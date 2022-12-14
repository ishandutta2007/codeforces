#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

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
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int dp[811][4111];

char a[4111][4111];
int pref[4111][4111];

int c(int l, int r){
    return (pref[r][r] - pref[r][l - 1] - pref[l - 1][r] + pref[l - 1][l - 1]) / 2;
}

void sol(int i, int l, int r, int optl, int optr){
    if(l > r)return;
    int mid = (l + r) >> 1;
    pll val = {2e9, 1e9};
    for(int k = optl; k <= min(optr, mid); k++){
        val = min(val, {dp[i - 1][k - 1] + c(k, mid), k});
    }

    if(val.se == 2e9)return;

    dp[i][mid] = val.fi;

    sol(i, l, mid - 1, optl, val.se);
    sol(i, mid + 1, r, val.se, optr);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)cin >> a[i][j];

    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= n; j++)dp[i][j] = 2e9;

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j] - '0';
    }

    for(int i = 1; i <= k; i++)sol(i, 1, n, 1, n);

    cout << dp[k][n] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}