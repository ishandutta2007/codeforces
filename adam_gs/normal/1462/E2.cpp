#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const long long MOD=1e9+7;
const int LIM=2e5+7;
long long sil[LIM], odwsil[LIM];
long long pot(long long a, long long b) {
	long long ans=1;
	while(b) {
		if(b%2==0) {
			a*=a;
			a%=MOD;
			b/=2;
		} else {
			ans*=a;
			ans%=MOD;
			--b;
		}
	}
	return ans;
}
long long smb(long long n, long long k) {
	if(k>n) return 0;
	return sil[n]*odwsil[k]%MOD*odwsil[n-k]%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=1;
	odwsil[0]=1;
	for(long long i=1; i<LIM; ++i) {
		sil[i]=sil[i-1]*i%MOD;
		odwsil[i]=pot(sil[i], MOD-2);
	}
	int t;
	cin >> t;
	while(t--) {
		long long n, m, r;
		cin >> n >> m >> r; --m;
		int T[n];
		rep(i, n) cin >> T[i];
		sort(T, T+n);
		long long ans=0, p=0, k=0;
		while(p<n) {
			while(k<n && T[k]-T[p]<=r) ++k;
			ans+=smb(k-p-1, m);
			if(ans>=MOD) ans-=MOD;
			++p;
		}
		cout << ans << '\n';
	}
}