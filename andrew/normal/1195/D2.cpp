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
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll step[MAXN];
 
ll mul(ll a, ll b){
    return (a * b) % mod;
}
 
ll add(ll a, ll b){
    return (a + b) % mod;
}
 
ll u(ll &a, ll b){
    a = add(a, b);
}
 
ll S[15][15], KOL[15][15];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    step[0] = 1;
 
    for(int i = 1; i <= 1e4; i++)step[i] = mul(step[i - 1], 10);
 
    vector <string> s(n);
 
    for(int i = 0; i < n; i++)cin >> s[i];
 
 
    for(int i = 0; i < n; i++){
        ll N = s[i].size();
        for(int j = 1; j < 12; j++){
            KOL[N][j]++;
            ll sc = 0, st = 0, kol = 1;
            for(int i1 = N - 1; i1 >= 0; i1--){
                sc = add(sc, mul(s[i][i1] - '0', step[st]));
                if(kol > j){
                    st++;
                }else st += 2;
                kol++;
            }
            u(S[N][j], sc);
        }
    }
 
    ll ans = 0;
 
    for(int i = 0; i < n; i++){
        ll N = s[i].size();
        for(int j = 1; j < 12; j++){
            ll sc = 0, st = 1, kol = 1;
            for(int i1 = N - 1; i1 >= 0; i1--){
                sc = add(sc, mul(s[i][i1] - '0', step[st]));
                kol++;
                if(kol > j)st++; else st += 2;
            }
            u(ans, S[j][N]);
            u(ans, mul(sc, KOL[j][N]));
        }
    }
 
    cout << ans << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}