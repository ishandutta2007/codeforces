# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 1e5+10;
ll a[xn], b[xn], n, m, r, c[xn];

bool cmp(ll a, ll b){
	if (a > b) return true;
	else return false;
}

bool check(ll x){
	ll p = 0;
	ll ans = 0;
	for (int i=0; i<x; i++){
		if (a[i] < b[x-i-1]) p += (b[x-i-1]-a[i]);
		ans += b[x-i-1];
	}
	ans -= r;
	if (ans < 0) ans = 0;
	c[x] = ans;
	if (p > r) return false;
	return true;
}

int main(){
	cin >> n >> m >> r;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i];
	sort(a,a+n,cmp), sort(b,b+m);
	ll l = 0, r = min(n,m), x;
	bool flag;
	while (l+1 < r){
		x = (l+r)/2;
		if (check(x)) l = x;
		else r = x;
	}
	if (check(r)) cout << r << ' ' << c[r];
	else cout << l << ' ' << c[l];
}