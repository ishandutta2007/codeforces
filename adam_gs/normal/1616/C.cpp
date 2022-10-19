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
void solve() {
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	if(n==1) {
		cout << 0 << '\n';
		return;
	}
	int ans=n;
	rep(i, n) rep(j, i) {
		rep(l, n) T[l]*=i-j;
		int akt=0;
		rep(l, n) {
			if(T[l]!=T[i]+((T[i]-T[j])/(i-j))*(l-i)) ++akt;
		}
		ans=min(ans, akt);
		rep(l, n) T[l]/=i-j;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}