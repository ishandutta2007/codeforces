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
        string s2="";
        for(ll i = 0;i<n;i++) if(s[i]=='b') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]=='t') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]=='r') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]=='y') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]=='g') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]=='u') s2+=s[i];
        for(ll i = 0;i<n;i++) if(s[i]!='t'&&s[i]!='r'&&s[i]!='y'&&s[i]!='g'&&s[i]!='u'&&s[i]!='b') s2+=s[i];
        cout<<s2<<'\n';
    }
}