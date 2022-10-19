#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n], gdzie[n], ans[n];
	rep(i, n) {
		cin >> T[i]; --T[i];
		gdzie[T[i]]=i;
		ans[i]=0;
	}
	ans[0]=1;
	int p=gdzie[0], k=gdzie[0];
	for(int i=1; i<n; ++i) {
		if(gdzie[i]<p) p=gdzie[i];
		if(gdzie[i]>k) k=gdzie[i];
		if(k-p==i) ans[i]=1;
	}
	rep(i, n) cout << ans[i];
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}