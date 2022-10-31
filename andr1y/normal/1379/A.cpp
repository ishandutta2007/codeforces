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
        string s;
        cin >> n >> s;
        string d = "abacaba";
        ll c=0;
        for(ll i = 0;i+6<n;i++){
            bool ok =1;
            for(ll j = 0;j<7;j++){
                if(s[i+j]!=d[j])ok=0;
            }
            if(ok) ++c;
        }
        if(c>1){
            cout<<"No\n";
            continue;
        }
        if(c==1){
            cout<<"Yes\n";
            for(ll i = 0;i<n;i++) if(s[i]=='?') s[i]='z';
            cout<<s<<'\n';
        }
        if(c==0){
            ll ff = 0;
            for(ll i = 0;i+6<n&&!ff;i++){
                bool ok =1;
                for(ll j = 0;j<7;j++){
                    if(s[i+j]!=d[j]&&s[i+j]!='?')ok=0;
                }
                if(ok){
                    string ss = s;
                    for(ll j = 0;j<7;j++){
                        if(ss[i+j]=='?') ss[j+i]=d[j];
                    }
                    c=0;
                    for(ll j = 0;j+6<n;j++){
                        bool ok =1;
                        for(ll k = 0;k<7;k++){
                            if(ss[j+k]!=d[k])ok=0;
                        }
                        if(ok) ++c;
                    }
                    if(c==1){
                        ff=1;
                        cout<<"Yes\n";
                        for(ll i = 0;i<n;i++) if(ss[i]=='?') ss[i]='z';
                        cout<<ss<<'\n';
                        break;
                    }
                }
            }
            if(!ff) cout<<"No\n";
        }
    }
}