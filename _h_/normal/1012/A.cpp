#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> a(2*n);
	trav(x, a) cin >> x;
	sort(all(a));

	ll ans = (a[n-1]-a[0])*(a[2*n-1] - a[n]);

	ll dif = 1e9+100;
	for(int i = 1; i < n; ++i) dif = min(dif, a[i+n-1]-a[i]);
	ans = min(ans, dif * (a[2*n-1] - a[0]));

	cout << ans << endl;
}