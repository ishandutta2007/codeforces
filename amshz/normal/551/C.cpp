#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;

ll n, m, a[maxn];

bool isval(ll t){
	ll b = 0, x = 0;
	for(ll i = n; i > 0; i--){
		if(a[i] <= b){
			b -= a[i];
		}
		else{
			ll d = a[i] - b;
			if(t - i <= 0) return 0;
			if(d % (t - i)) b = t - i - d % (t - i);
			else b = 0;
			x += (d + t - i - 1) / (t - i);
		}
	}
	return (x <= m);
}

int main(){
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	ll l = 0, r = 1e15, mid;
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << r << endl;
	return 0;
}