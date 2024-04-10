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
 
ll dp[23][N];
 
ll kol[MAXN];
 
ll le, ri, res = 0;
 
vector <ll> a;
 
ll f(ll x){
    return (x * (x - 1)) / 2;
}
 
ll c(ll l, ll r){
    while(le > l){
        res -= f(kol[a[le - 1]]);
        kol[a[le - 1]]++;
        res += f(kol[a[le - 1]]);
        le--;
    }
    while(le < l){
        res -= f(kol[a[le]]);
        kol[a[le]]--;
        res += f(kol[a[le]]);
        le++;
    }
 
    while(ri < r){
        res -= f(kol[a[ri + 1]]);
        kol[a[ri + 1]]++;
        res += f(kol[a[ri + 1]]);
        ri++;
    }
    while(ri > r){
        res -= f(kol[a[ri]]);
        kol[a[ri]]--;
        res += f(kol[a[ri]]);
        ri--;
    }
    return res;
}
 
void sol(int i, int l, int r, int optl, int optr){
    if(l > r)return;
    int mid = (l + r) >> 1;
    pll val = {2e18, 1e18};
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
 
    ll n, k;
    cin >> n >> k;
 
    a.resize(n + 1);
 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
 
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= n; j++)dp[i][j] = 1e18;
 
    dp[0][0] = 0;
 
    for(int i = 1; i <= k; i++){
        res = 0;
        le = 1, ri = 1;
        res = 0;
        for(int j = 1; j <= n; j++)kol[j] = 0;
        kol[a[1]] = 1;
        sol(i, 1, n, 1, n);
    }
 
    cout << dp[k][n] << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}