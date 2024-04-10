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
const ll N = 3e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll mod = 998244353;
 
ll add(ll a, ll b){
    return (a + b >= mod ? a + b - mod : a + b);
}
 
ll mul(ll a, ll b){
    return (a * b) % mod;
}
 
void u(ll &a, ll b){
    a = mul(a, b);
}
 
bool dp[N + 5][20];
 
bool f[MAXN], f1[MAXN];
 
bool prost[MAXN];
ll last[MAXN];
 
bool F[MAXN];
ll p[MAXN];
ll S[MAXN];
 
ll func(ll x){
    vector <ll> a;
    ll b = x, t;
    while(b != 1){
        t = p[b];
        while(b % t == 0)b /= t;
        a.p_b(t);
    }
    ll res = 0;
    for(int i = 1; i < pw(a.size()); i++){
        bool xt = 0;
        ll p = 1;
        for(int j = 0; j < a.size(); j++)if((i & pw(j))){
            p *= a[j];
            xt ^= 1;
        }
        if(xt)res += S[p];
        else res -= S[p];
    }
    return res;
}
 
ll Kek[MAXN], us[MAXN];
 
void fact(ll x){
    while(x != 1){
        cout << p[x] << " ";
        x /= p[x];
    }
    cout << endl;
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    for(int i = 2; i <= N; i++)if(!p[i]){
        p[i] = i;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i)p[j] = i;
    }
 
    ll n;
    cin >> n;
    vector <ll> a;
    while(n--){
        ll x;
        cin >> x;
        //fact(x);
        f[x] = 1;
        a.p_b(x);
    }
 
    for(int i = 1; i <= N; i++)dp[i][1] = f[i];
 
    if(dp[1][1])vout(1);
 
    for(int step = 1; step < 8; step++){
        for(int i = 1; i <= N; i++){
            if(dp[i][step]){
                dp[i][step + 1] = 1;
                continue;
            }
            ll l = 1, r = N / i, Last = 0, pos, kol = 0;
            for(int j = 1; j <= r; j++){
                f1[j] = f[i * j];
                kol += f1[j];
            }
 
            for(int j = 1; j <= r; j++){
                for(int k = j; k <= r; k += j)S[j] += f1[k];
            }
 
            for(int j = 1; j <= r; j++)if(dp[i * j][step]){
                if(func(j) != kol){
                    dp[i][step + 1] = 1;
                    break;
                }
            }
 
            for(int j = 1; j <= r; j++)S[j] = 0;
        }
        if(dp[1][step + 1])vout(step + 1);
    }
 
    vout(-1);
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}