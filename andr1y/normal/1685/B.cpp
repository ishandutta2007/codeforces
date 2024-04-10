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
        ll n, a, b, c, d;
        string s;
        cin >> a >> b >> c >> d >> s;
        n=s.length();
        ll nbz=1, ns=s[0]-'A', ac=0, bc=0, free=0;
        if(s[0]=='A') ac++;
        else bc++;
        s.push_back(s.back());
        vector<int> soc, sod;
        for(int i = 1;i<=n;i++){
            if(i<n){
                if(s[i]=='A') ac++;
                else bc++;
            }
            if(s[i]!=s[i-1]){
                nbz++;
            }else{
                if(nbz%2==1) free+=nbz/2;
                else{
                    if(ns==0) soc.push_back(nbz/2-1);
                    else sod.push_back(nbz/2-1);
                }
                nbz=1;
                ns=(s[i]-'A');
            }
        }
        if(a+c+d != ac || b+c+d != bc){
            cout<<"NO\n";
            continue;
        }
        sort(soc.begin(), soc.end(), greater<ll>());
        while(soc.size() && c > 0){
            ll tk = min<ll>(soc.back()+1, c);
            c-=tk;
            soc.back()-=tk;
            if(soc.back()<=0) soc.pop_back();
        }
        for(auto i : soc) free+=i;
        sort(sod.begin(), sod.end(), greater<ll>());
        while(sod.size() && d > 0){
            ll tk = min<ll>(sod.back()+1, d);
            d-=tk;
            sod.back()-=tk;
            if(sod.back()<=0) sod.pop_back();
        }
        for(auto i : sod) free+=i;
        if(c+d <= free) cout<<"YES\n";
        else cout<<"NO\n";
    }
}