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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll pref[110][26], pref1[110][26], mb[26];
ll dp[1001][1001];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll q;
    cin >> q;
 
    while(q--){
        string s, t, p;
        cin >> s >> t >> p;
        s = "+" + s;
        t = "+" + t;
        for(int j = 0; j < 26; j++)mb[j] = 0;
        for(auto i : p)mb[i - 'a']++;
        ll n = s.size() - 1, m = t.size() - 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++)pref[i][j] = pref[i - 1][j];
            pref[i][s[i] - 'a']++;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 26; j++)pref1[i][j] = pref1[i - 1][j];
            pref1[i][t[i] - 'a']++;
        }
 
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)dp[i][j] = 0;
        dp[0][0] = 1;
 
        string ans = "NO";
 
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < m; j++){
                if(i < n && s[i + 1] == t[j + 1]){
                    dp[i + 1][j + 1] |= dp[i][j];
                }
                ll val = t[j + 1] - 'a';
                if(mb[val] - (pref1[j][val] - pref[i][val]) > 0){
                    dp[i][j + 1] |= dp[i][j];
                }
            }
        }
        if(dp[n][m])ans = "YES";
        cout << ans << "\n";
 
    }
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}