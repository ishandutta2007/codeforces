//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        ll a0=0, a1=0;
        for(auto i : s) if(i=='1') a1++; else a0++;
        ll d0 = 0, d1=0;
        ll ans = min(a0, a1);
        for(ll i = 0;i<s.length();i++){
            if(s[i]=='1') d1++; else d0++;
            ans=min(ans, min(d0+a1-d1, d1+a0-d0));
        }
        cout<< ans<<'\n';
    }
}