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
#define pci pair<char,int>
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
const ll N = 4e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
int z[MAXN];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    vector <pair <char, ll>> a, b;
 
    for(int i = 0; i < n; i++){
        char x, y;
        ll val;
        cin >> val >> y >> x;
        if(!a.empty() && a.back().fi == x){
            val += a.back().se;
            a.pop_back();
        }
        a.p_b({x, val});
    }
 
    for(int i = 0; i < m; i++){
        char x, y;
        ll val;
        cin >> val >> y >> x;
        if(!b.empty() && b.back().fi == x){
            val += b.back().se;
            b.pop_back();
        }
        b.p_b({x, val});
    }
 
    n = a.size();
    m = b.size();
 
    if(m == 1){
        ll ans = 0;
        for(auto i : a)if(i.fi == b[0].fi)ans += max(0ll, i.se - b[0].se + 1);
        vout(ans);
    }
 
    if(m == 2){
        ll ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(a[i].fi != b[0].fi || a[i].se < b[0].se)continue;
            if(a[i + 1].fi != b[1].fi || a[i + 1].se < b[1].se)continue;
            ans++;
        }
        vout(ans);
    }
 
    vector <pci> unt;
 
    for(int i = 1; i < m; i++){
        unt.p_b(b[i]);
    }
 
    for(auto i : a){
        unt.p_b(i);
    }
 
    z[0] = 1e9;
 
    for(int i = 1, l = 0, r = 0; i < n + m; i++){
        if(i <= r)z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n + m && unt[z[i]] == unt[i + z[i]])++z[i];
        if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
    ll ans = 0;
    for(int i = 1; i < n - 1; i++)if(z[i + m - 1] >= m - 2){
        if(a[i - 1].fi != b[0].fi || a[i - 1].se < b[0].se)continue;
        if(a[i + m - 2].fi != b.back().fi || a[i + m - 2].se < b.back().se)continue;
        ans++;
    }
 
    cout << ans << "\n";
 
 
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}