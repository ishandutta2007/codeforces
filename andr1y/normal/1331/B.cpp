//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll a;
	cin >> a;
	for(ll i = 2;i*i<=a;i++){
		if(a%i==0){
			cout << i << a/i << '\n';
			exit(0);
		}
	}
}