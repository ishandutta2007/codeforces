// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string s;
        cin >> n >> s;
        string r="";
        char last=0;
        for(ll i = 0;i<n;i++){
            ll e = s[i]-'0';
            if(e==1){
                if(last!='2') r+='1', last='2';
                else r+='0', last='1';
            }else{
                if(last!='1') r+='1', last='1';
                else r+='0', last='0';
            }
        }
        cout<<r<<'\n';
    }
}