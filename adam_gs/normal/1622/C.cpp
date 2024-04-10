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
const ll INF=1e18+7;
void solve() {
	ll n, k, sum=0;
	cin >> n >> k;
	ll T[n];
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	if(sum<=k) {
		cout << 0 << '\n';
		return;
	}
	ll ans=sum-k;
	sort(T, T+n);
	rep(i, n-1) {
		sum-=T[n-i-1]-T[0];
		ll w=(sum-k+i+1)/(i+2);
		if(sum<=k) w=0;
		ans=min(ans, w+i+1);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}