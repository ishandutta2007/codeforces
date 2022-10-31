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
        ll n;
        string s;
        cin >> n >> s;
        if(n&1){
            bool hp=0;
            for(ll i =0;i<n;i+=2){
                if((s[i]-'0')&1) hp=1;
            }
            if(hp) cout<<"1\n";
            else cout<<"2\n";
        }else{
            bool he=0;
            for(ll i = 1;i<n;i+=2){
                if((s[i]-'0')%2==0) he=1;
            }
            if(he) cout<<"2\n";
            else cout<<"1\n";
        }
	}
}