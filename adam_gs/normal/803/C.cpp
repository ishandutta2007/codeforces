#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
bool spr(long long n, long long k, long long x) {
	if(k*(k+1)>100000000000/x) return false;
	return n%x==0 && k*(k+1)/2*x<=n;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k, ans=-1;
	cin >> n >> k;
	if(k>100000000) {
		cout << -1;
		return 0;
	}
	for(long long i=1; i*i<=n; ++i) {
		if(n%i==0) {
			if(spr(n, k, i)) ans=max(ans, i);
			if(spr(n, k, n/i)) ans=max(ans, n/i);
		}
	}
	if(ans==-1) {
		cout << -1;
		return 0;
	}
	rep(i, k-1) {
		cout << ans*(i+1) << " ";
		n -= ans*(i+1);
	}
	cout << n << '\n';
}