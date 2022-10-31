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
        string s;
        cin >> s;
        ll o0=0, o1=0, res=0;
        for(ll i = 0;i<s.length();i++){
            if(s[i]=='(') o0++;
            if(s[i]=='[') o1++;
            if(s[i]==')'){
                if(o0) o0--, res++;
            }
            if(s[i]==']'){
                if(o1) o1--, res++;
            }
        }
        cout<<res<<'\n';
    }
}