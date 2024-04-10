#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qabs(ll a){
	return (a < 0) ? -a : a;
}

int T;
int n;
ll k;
ll a[200200];
ll diff[200200];
ll g = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n) cin >> a[i];
		rep(i, n-1) diff[i] = qabs(a[i + 1] - a[i]);
		g = 0;
		rep(i, n-1) g = __gcd(g, diff[i]);
		if((a[0] % g + g) % g == (k % g + g) % g) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
	return 0;
}