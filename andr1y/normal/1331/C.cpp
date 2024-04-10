//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll ans = 0;
	ans |= ((n>>4)&1)<<0;//
	ans |= ((n>>1)&1)<<1;//
	ans |= ((n>>3)&1)<<2;
	ans |= ((n>>2)&1)<<3;
	ans |= ((n>>0)&1)<<4;//
	ans |= ((n>>5)&1)<<5;//
	cout << ans << '\n';
}