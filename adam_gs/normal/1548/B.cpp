#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
ll tr[4*LIM], T[LIM], N;
ll cnt(int l, int r) {
	l+=N; r+=N;
	ll ans=__gcd(tr[l], tr[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=__gcd(ans, tr[l+1]);
		if(r%2==1) ans=__gcd(ans, tr[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	N=1;
	while(N<n) N*=2;
	rep(i, n) cin >> T[i];
	rep(i, 2*N) tr[i]=0;
	rep(i, n-1) tr[N+i]=abs(T[i]-T[i+1]);
	for(int i=N-1; i>=0; --i) tr[i]=__gcd(tr[2*i], tr[2*i+1]);
	int ans=1, k=0;
	rep(i, n-1) {
		if(tr[N+i]==1) {
			k=i+1;
			continue;
		}
		ll akt=cnt(k, i);
		while(akt==1) {
			++k;
			akt=cnt(k, i);
		}
		ans=max(ans, i-k+2);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}