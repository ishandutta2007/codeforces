//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll k;
	cin >> k;
	if(k == 0){
		cout << "1 1\n1\n";
	}else{
		cout << "2 3\n";
		cout << (1LL<<17)+k << " " << (1LL<<17) << " 0\n";
		cout << k <<" " << (1LL<<18)-1 << " " << k << '\n';
	}
}