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
ll cnta[17];
ll cntb[17];
ll cntab[17][17];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        memset(cnta, 0, sizeof cnta);
        memset(cntb, 0, sizeof cntb);
        memset(cntab, 0, sizeof cntab);
        for(ll i = 0;i<n;i++){
            string s;
            cin >> s;
            cnta[s[0]-'a']++;
            cntb[s[1]-'a']++;
            cntab[s[0]-'a'][s[1]-'a']++;
        }
        ll r = 0;
        for(char I = 'a';I<='k';I++){
            for(ll J = 'a';J<='k';J++){
                ll i = I-'a', j=J-'a';
                r += cntab[i][j]*(cnta[i]-cntab[i][j] + cntb[j] - cntab[i][j]);
            }
        }
        r>>=1;
        cout<<r<<'\n';
    }
}