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
	ll n;
	cin >> n;
	pair<ll,ll>T[n];
	ll ans[n], sum=0;
	rep(i, n) {
		cin >> T[i].st;
		T[i].nd=i;
	}
	sort(T, T+n);
	reverse(T, T+n);
	rep(i, n) {
		if(i%2) ans[T[i].nd]=-i/2-1;
		else ans[T[i].nd]=i/2+1;
		sum+=2*T[i].st*abs(ans[T[i].nd]);
	}
	cout << sum << '\n' << 0 << " ";
	rep(i, n) cout << ans[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}