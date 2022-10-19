#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll LIM=5e5+7, INF=1e18+7;
ll T[LIM], dp[LIM][2][2], n; // prefiks, czy biore aktualny, jakie k (aktualne albo poprzednie)
ll f(int x) { // minimalna liczba ruchow zeby x bylo lokalnym maximum
	ll ans=0;
	if(x>0) ans+=max(T[x-1]-T[x]+1, 0ll);
	if(x<n-1) ans+=max(T[x+1]-T[x]+1, 0ll);
	return ans;
}
ll f2(int x) { // minimalna liczba ruchow zeby x bylo lokalnym maximum jesli x-2 jest
	ll ans=0;
	if(x<n-1) ans+=max(T[x+1]-T[x]+1, 0ll);
	ll p=min(T[x-1], T[x-2]-1);
	ans+=max(p-T[x]+1, 0ll);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, n) cin >> T[i];
	if(n==1) {
		cout << 0 << '\n';
		return 0;
	}
	rep(i, n) dp[i][1][0]=INF;
	rep(nr, (n+1)/2) {
		// recznie licze pierwszy i drugi
		dp[0][0][1]=dp[0][1][1]=INF;
		if(nr==0) dp[0][1][1]=f(0);
		dp[1][0][1]=min(dp[0][0][1], dp[0][1][1]);
		dp[1][1][1]=INF;
		if(nr==0) dp[1][1][1]=f(1);
		for(int i=2; i<n; ++i) {
			dp[i][0][1]=min(dp[i-1][0][1], dp[i-1][1][1]);
			dp[i][1][1]=min(dp[i-2][0][0]+f(i), dp[i-2][1][0]+f2(i));
		}	
		cout << min(dp[n-1][0][1], dp[n-1][1][1]) << " ";
		rep(i, n) {
			dp[i][0][0]=dp[i][0][1];
			dp[i][1][0]=dp[i][1][1];
		}
		rep(i, n) dp[i][0][1]=dp[i][1][1]=0;
	}
	cout << '\n';
}