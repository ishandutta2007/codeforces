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
	ll n, a, b;
	cin >> n >> a >> b;
	ll T[n+1];
	T[0]=0;
	rep(i, n) cin >> T[i+1];
	ll sum=0, ans=INF;
	for(ll i=n; i>=0; --i) {
		ans=min(ans, T[i]*(a+b)+(sum-T[i]*(n-i))*b);
		sum+=T[i];
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}