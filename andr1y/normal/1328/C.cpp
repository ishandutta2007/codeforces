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
		ll n;
		string s;
		cin >> n >> s;
		string a = "", b = "";
		bool wm = 0;
		for(ll i = 0;i<n;i++){
			if(s[i] == '0') a+='0', b+='0';
			else if(s[i] == '1'){
				if(wm){
					a+='0', b+='1';
				}else{
					a+='1', b+='0';
					wm = 1;
				}
			}else if(s[i] == '2'){
				if(wm){
					a+='0', b+='2';
				}else{
					a+='1', b+='1';
				}
			}
		}
		cout << a << '\n';
		cout << b << '\n';
	}
}