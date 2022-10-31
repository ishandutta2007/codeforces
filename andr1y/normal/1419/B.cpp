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
        ll n, r = 0;
        cin >> n;
        for(ll i = 1;i<32;i++){
            ll us = (1LL<<i)-1;
            ll uk = (us*(us+1))/2;
            if(uk<=n){
                n-=uk;
                r++;
            }else break;
        }
        cout<<r<<'\n';
	}
}