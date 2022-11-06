#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int dp[101][10001]; // dp[k][b] is max total capacity if we've added b/2 extra water

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi a(n), b(n);
	rep(i,0,n) cin >> a[i] >> b[i];

	rep(i,0,101) rep(j,0,10001) dp[i][j] = -1e8;
	dp[0][0] = 0;

	rep(ix,0,n)
		rrep(k,0,ix+1)
			rep(s,0, k * 100 + 1){
				dp[k+1][s + b[ix]] = max(dp[k+1][s+b[ix]], dp[k][s] + a[ix]);
			}
	
	int tot = 0;
	trav(x, b) tot += x;

	rep(k,1,n+1){
		int ans = 0;
		rep(s,0, k * 100 + 1)
			ans = max(ans, min(2 * dp[k][s], tot + s));
		cout << ans / 2. << " ";
	}
	cout << endl;
}