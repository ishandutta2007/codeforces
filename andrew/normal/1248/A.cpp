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
#define sz(x) (int)x.size()
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll t;
    cin >> t;
 
    while(t--){
        ll n, m;
        cin >> n;
        ll ans = 0;
        map <ll, ll> mp;
        vector <ll> kol(2);
        ll nn = n;
        while(n--){
            ll x;
            cin >> x;
            ans += mp[x];
            kol[x % 2]++;
            mp[x]++;
        }
 
        mp.clear();
        cin >> m;
        ll mm = m;
        while(m--){
            ll x;
            cin >> x;
            ans += mp[x];
            ans += kol[(2 - x % 2) % 2];
            mp[x]++;
        }
        cout <<  ans << "\n";
    }
 
    return 0;
}