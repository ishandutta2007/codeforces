#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
	int n;
	cin >> n;
	int T[2*n], mi[2*n+1];
	rep(i, 2*n+1) mi[i]=INF;
	mi[n]=n;
	rep(i, 2*n) cin >> T[i];
	ll dt=0;
	rep(i, n) {
		if(T[i]==1) ++dt;
		else --dt;
		mi[n+dt]=n-i-1;
	}
	int ans=n+mi[n];
	dt=0;
	for(int i=2*n-1; i>=n; --i) {
		if(T[i]==1) --dt;
		else ++dt;
		ans=min(ans, i-n+mi[n+dt]);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}