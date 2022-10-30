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
        ll n = s.length();
        bool f=0;
        for(ll w=0;w<2;w++){
            for(ll e=0;e<2;e++){
                for(ll r=0;r<2;r++){
                    ll op2=0;
                    bool ok=1;
                    for(ll i =0;i<n;i++){
                        bool op=0;
                        if(s[i]=='A') op=w;
                        if(s[i]=='B') op=e;
                        if(s[i]=='C') op=r;
                        if(op) op2++;
                        else op2--;
                        if(op2<0) ok=0;
                    }
                    if(op2!=0) ok=0;
                    if(ok) f=1;
                }
            }
        }
        if(f)cout<<"yes\n";
        else cout<<"no\n";
    }
}