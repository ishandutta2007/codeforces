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

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> a(n, 0);
        if(k&1){
            for(auto &i : s) i=('0'+'1')-i;
        }
        for(ll j =0;j<n;j++){
            char &i = s[j];
            if(i == '0' && k) i++, --k, a[j]++;
        }
        if(k&1) s.back()--, k--, a.back()++;
        if(k) a[0]+=k;
        cout<<s<<'\n';
        for(auto i : a) cout<<i<<' ';
        cout<<'\n'; 
    }
}