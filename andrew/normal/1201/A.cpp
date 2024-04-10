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
 
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    vector <ll> a(m);
    vector <string>  s(n);
 
    for(int i = 0; i < n; i++)cin >> s[i];
 
    vector <ll> kol(26);
 
    for(int i = 0; i < m; i++)cin >> a[i];
 
    ll ans = 0;
 
    for(int j = 0; j < m; j++){
        for(int i = 0; i < 26; i++)kol[i] = 0;
        for(int i = 0; i < n; i++)kol[s[i][j] - 'A']++;
        ans += *max_element(all(kol)) * a[j];
    }
 
    cout << ans << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}