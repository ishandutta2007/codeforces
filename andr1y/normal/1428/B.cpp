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
        cin >> n>>s;
        ll cl=0, cr=0;
        for(ll i = 0;i<n;i++){
            if(s[i]=='<') cr++;
            else if(s[i]=='>') cl++;
        }
        ll res=0;
        for(ll i = 0;i<n;i++){
            ll p = (i-1+n)%n;
            if(s[i]=='-'||s[p]=='-') res++;
            else if(s[i]=='>'&&!cr) res++;
            else if(s[p]=='<'&&!cl) res++;
        }
        cout<<res<<'\n';;
    }
}