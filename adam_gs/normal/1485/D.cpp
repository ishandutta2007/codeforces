#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
ll nwd(ll a, ll b) {
	if(!a) return b;
	return nwd(b%a, a);
}
ll nww(ll a, ll b) {
	return a/nwd(a, b)*b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll ans=1;
	rep(i, 16) {
		ans=nww(ans, i+1);
	}
	int n, m;
	cin >> n >> m;
	int T[n][m];
	rep(i, n) rep(j, m) cin >> T[i][j];
	rep(i, n) rep(j, m) {
		if((i+j)%2==0) {
			cout << ans << " ";
			continue;
		}
		int p=T[i][j];
		p*=p;
		p*=p;
		cout << ans-p << " ";
		if(j==m-1) cout << '\n';
	}
}