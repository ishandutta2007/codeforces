// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n, k;
        string s;
        cin >> n >> k >> s;
        bool ok =1;
        ll a0=0, a1=0, aq=0;
        for(ll i = 0;i<k;i++){
            ll c0=0, c1=0, cq=0;
            for(ll j = i;j<n;j+=k){
                if(s[j]=='1') c1++;
                if(s[j]=='0') c0++;
                if(s[j]=='?') cq++;
            }
            if(c1&&c0){
                ok=0;
                break;
            }
            if(c1) a1++;
            else if(c0) a0++;
            else aq++;
        }
        if(ok&&(a0<=k/2&&a1<=k/2)) cout<<"YES\n";
        else cout<<"NO\n";
	}
}