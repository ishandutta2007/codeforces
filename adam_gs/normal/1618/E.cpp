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
	ll B[n], C[n], A[n];
	rep(i, n) cin >> B[i];
	rep(i, n) C[i]=B[(i+n-1)%n]-B[i];
	ll a1=B[n-1];
	rep(i, n) {
		ll x=C[i]-C[0];
		if(x%n) {
			cout << "NO\n";
			return;
		}
		x/=n;
		x*=(n-i);
		a1-=x;
	}
	a1*=2;
	if(a1%(n*(n+1))) {
		cout << "NO\n";
		return;
	}
	a1/=n*(n+1);
	rep(i, n) {
		A[i]=(C[i]-C[0])/n+a1;
		if(A[i]<=0) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	rep(i, n) cout << A[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}