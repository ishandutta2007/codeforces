#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;

ll dp[N];
ll last[26];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        for(ll i = 0;i<26;i++) last[i] = 0;
        dp[0]=0;
        for(ll i = 1;i<=(ll)s.length();i++){
            dp[i]=dp[i-1];
            ll x = s[i-1]-'a';
            if(last[x]) dp[i]=max(dp[i], dp[last[x]-1]+2);
            last[x] = i;
        }
        cout<<s.length()-dp[s.length()]<<'\n';
    }
}