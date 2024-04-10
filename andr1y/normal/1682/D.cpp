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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll z=0,o=0;
        for(ll i = 0;i<n;i++){
            if(s[i]=='1') ++o;
            else ++z;
        }
        s.push_back(s[0]);
        bool f=0;
        for(ll i = 0;i<n;i++){
            if(s[i]=='1'){
                ll vg = (o-(s[i+1]=='1'?1:0));
                vg&=1;
                if(s[i+1]-'0'==vg){
                    f=1;
                    cout<<"YES\n";
                    ll tk = (i+1)%n;
                    for(ll j = 0;j<n;j++){
                        if(j==tk) continue;
                        ll nx = (j+1)%n;
                        if(nx==tk) nx=(nx+1)%n;
                        if(s[j]=='0') cout<<nx+1<<' '<<j+1<<'\n';
                        if(s[j]=='1') cout<<nx+1<<' '<<tk+1<<'\n';
                    }
                    break;
                }
            }
        }
        if(!f) cout<<"NO\n";
    }
}