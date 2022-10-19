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
	ll T[n], G[2];
	G[0]=G[1]=0;
	rep(i, n) {
		cin >> T[i];
		G[i%2]=__gcd(G[i%2], T[i]);
	}
	bool ok[2];
	ok[0]=ok[1]=true;
	rep(i, n) {
		if(T[i]%G[(i+1)%2]==0) ok[(i+1)%2]=false;
	}
	rep(i, 2) {
		if(ok[i]) {
			cout << G[i] << '\n';
			return;
		}
	}
	cout << 0 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}