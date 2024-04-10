#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		ll k;
		cin >> n >> k;
		ll T[n], ans=0;
		rep(i, n) {
			cin >> T[i];
		}
		ll pre=T[0];
		for(int i=1; i<n; ++i) {
			ll z=(100*T[i]+k-1)/k-pre;
			ans=max(ans, z);
			pre+=T[i];
		}
		cout << ans << '\n';
	}
}