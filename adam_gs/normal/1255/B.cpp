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
	int n, m, ans=0;
	cin >> n >> m;
	int T[n];
	rep(i, n) {
		cin >> T[i];
		ans+=2*T[i];
	}
	if(n!=m || n==2) {
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
	rep(i, n) cout << i+1 << " " << (i+1)%n+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}