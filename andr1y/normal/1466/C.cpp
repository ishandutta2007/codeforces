// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
char mex(char a, char b, char c, char d){
    bool k[5] = {0};
    if(a<'f') k[a-'a']=1;
    if(b<'f') k[b-'a']=1;
    if(c<'f') k[c-'a']=1;
    if(d<'f') k[d-'a']=1;
    for(ll i = 0;i<5;i++) if(!k[i]) return 'a'+i;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        ll n = s.length(), res=0;
        s+='~';
        s+='~';
        s="~"+s;
        for(ll i = 2;i<=n;i++){
            if(s[i]==s[i-1]||s[i]==s[i-2]){
                res++;
                s[i]=mex(s[i-2], s[i-1], s[i+1], s[i+2]);
            }
        }
        cout<<res<<'\n';
    }
}