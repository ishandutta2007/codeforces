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
 
vector <ll> v[MAXN];
ll ans[1001][1001];
ll n, k, d;
void build(ll deep, ll tl, ll tr){
    if(tl == tr)return;
    if(deep > d)vout(-1);
    if(tr - tl + 1 <= k){
        for(int i = tl; i <= tr; i++)ans[deep][i] = i - tl + 1;
        return;
    }
    ll kolr = (tr - tl + 1) / k + ((tr - tl + 1) % k > 0), koll = (tr - tl + 1) / k, KOl = (tr - tl + 1) % k;
    ll uk = tl;
    for(int step = 1; step <= KOl; step++){
        for(int i = uk; i <= uk + kolr - 1; i++)ans[deep][i] = step;
        build(deep + 1, uk, uk + kolr - 1);
        uk += kolr;
    }
 
    for(int step = KOl + 1; step <= k; step++){
        for(int i = uk; i <= uk + koll - 1; i++)ans[deep][i] = step;
        build(deep + 1, uk, uk + koll - 1);
        uk += koll;
    }
 
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k >> d;
    if(n == 1){
        for(int i = 1; i <= d; i++)cout << "1\n";
        return 0;
    }
    if(n > 1 && k == 1)vout(-1);
 
    if(d >= n){
        for(int i = 1; i <= d; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)cout << "2 ";
                else cout << "1 ";
            }
            cout << "\n";
        }
        return 0;
    }
 
    if(k >= n){
        for(int i = 1; i <= d; i++){
            for(int j = 1; j <= n; j++)cout << j << " ";
            cout << "\n";
        }
        return 0;
    }
 
    for(int i = 1; i <= d; i++)
        for(int j = 1; j <= n; j++)ans[i][j] = 1;
    build(1, 1, n);
    for(int step = 1; step <= d; step++){
        for(int i = 1; i <= n; i++)cout << ans[step][i] << " ";
        cout << "\n";
    }
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}