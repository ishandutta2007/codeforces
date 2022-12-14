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
 
map <ll, ll> mp;
 
ll Log[MAXN];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, I;
    cin >> n >> I;
 
    vector <ll> a(n + 1);
 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
 
    ll st = 0, k = 1;
 
    for(int i = 1; i < MAXN; i++){
        while(k < i){
            st++;
            k *= 2;
        }
        Log[i] = st;
    }
 
    vector <ll> c, b;
 
    vector <ll> pref;
 
    ll S = 0;
 
    for(auto i : mp){
        c.p_b(i.fi);
        S += i.se;
        pref.p_b(S);
    }
 
    ll M = c.size(), ans = 1e18;
 
    for(int i = 0; i < M; i++){
        ll l = i, r = M - 1;
        while(l < r){
            ll c = (l + r + 1) >> 1;
            if(n * Log[c - i + 1] > I * 8)r = c - 1; else l = c;
        }
 
        ll S = 0;
        if(i)S += pref[i - 1];
        S += pref[M - 1];
        S -= pref[l];
        ans = min(ans, S);
    }
 
    cout << ans << "\n";
 
 
 
    return 0;
}