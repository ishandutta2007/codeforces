// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string s, r="", r2="";
        cin >> n>>s;
        ll i1=-1, i2=n;
        for(ll i = 0;i<n;i++){
            if(s[i]=='1') break;
            r+=s[i];
            i1=i;
        }
        for(ll i = n-1;i>=0;i--){
            if(s[i]=='0') break;
            r2+=s[i];
            i2=i;
        }
        if(i1+1!=i2)r+="0";
        cout<<r<<r2<<'\n';
    }
}