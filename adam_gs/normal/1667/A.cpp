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
	int n;
	cin >> n;
	ll T[n], ans=INF;
	rep(i, n) cin >> T[i];
	rep(i, n) {
		ll p=0, akt=0;
		for(int j=i+1; j<n; ++j) {
			p+=akt/T[j]+1;
			akt=(akt/T[j]+1)*T[j];
		}
		akt=0;
		for(int j=i-1; j>=0; --j) {
			p+=akt/T[j]+1;
			akt=(akt/T[j]+1)*T[j];
		}
		ans=min(ans, p);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}