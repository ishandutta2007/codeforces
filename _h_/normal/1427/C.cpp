#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int r, n;
	cin >> r >> n;
	++n;

	vi t(n), x(n), y(n+1);
	t[0] = 0;
	x[0] = 1;
	y[0] = 1;
	rep(i,1,n) cin >> t[i] >> x[i] >> y[i];

	vi dp(n, -n), cert(n, -n);
	dp[0] = 0;
	rep(i,0,n){
		dp[i] = max(dp[i], cert[i]);
		if(i+1 < n) cert[i+1] = max(cert[i+1], cert[i]);
		int v = dp[i]+1;
		for(int j = i+1; j < i+998 && j < n; ++j){
			if(abs(x[j]-x[i])+abs(y[j]-y[i]) <= t[j]-t[i])
				dp[j] = max(dp[j], v);
		}
		if(i+998 < n) cert[i+998] = max(cert[i+998], v);
	}

	int ans = 0;
	trav(x, dp) ans = max(ans, x);

	cout << ans << endl;
}