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
const ll INF=1e18+7;
ll A[LIM], B[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];
	ll ans=INF;
	rep(a, 3) rep(b, 3) {
		ll akt=0;
		if(!a) akt+=abs(A[0]-B[0]);
		else if(a==1) akt+=abs(A[0]-B[n-1]);
		else {
			ll mi=INF;
			rep(i, n) mi=min(mi, abs(A[0]-B[i]));
			akt+=mi;
		}
		if(!b) akt+=abs(A[n-1]-B[0]);
		else if(b==1) akt+=abs(A[n-1]-B[n-1]);
		else {
			ll mi=INF;
			rep(i, n) mi=min(mi, abs(A[n-1]-B[i]));
			akt+=mi;
		}
		if(a && b) {
			ll mi=INF;
			rep(i, n) mi=min(mi, abs(B[0]-A[i]));
			akt+=mi;
		}
		if(a!=1 && b!=1) {
			ll mi=INF;
			rep(i, n) mi=min(mi, abs(B[n-1]-A[i]));
			akt+=mi;
		}
		ans=min(ans, akt);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}