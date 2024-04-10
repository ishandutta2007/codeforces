# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int xn = 2e5+10;
ll a[xn], n, k, r, m;
bool f[xn];
 
bool check(ll x){
	for (int i=0; i<x; i++) f[a[i]-1] = 1;
	ll t = 0;
	ll q = 0;
	for (int i=0; i<n; i++){
		if (f[i] == 0) q += 1;
		else q = 0;
		if (q == r) t += 1, q = -1;//, cout << i << ' ';
	}
	for (int i=0; i<n; i++) f[i] = 0;
	if (t < k) return false;
	return true;
}
 
int main(){
	cin >> n >> k >> r >> m;
	for (int i=0; i<m; i++) cin >> a[i];
	ll l = 0, r = n, mid;
	//for (int i=0; i<n; i++){
	//	cout << check(i+1) << endl;
	//}
	while (l+1 < r){
		mid = (l+r)/2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	ll ans = l;
	if (check(r)) ans = r;
	ans += 1;
	if (ans == n+1){
		cout << -1;
		return 0;
	}
	cout << ans;
}