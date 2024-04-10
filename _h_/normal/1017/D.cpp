#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int dp[2][1<<12][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;

	vi w(n);
	trav(x, w) cin >> x;
	reverse(all(w));

	rep(_,0,m){
		string s;
		cin >> s;
		int r = 0;
		trav(c, s) r = r*2 + (c-'0');
		++dp[0][r][0];
	}
	rep(l,0,n){
		int f = l%2;
		rep(r,0,1<<n) rep(k,0,101) dp[1-f][r][k] = 0;
		rep(r,0,1<<n){
			rep(k,0,101)
				dp[1-f][r^(1<<l)][k] += dp[f][r][k];
			rep(k,w[l],101)
				dp[1-f][r][k] += dp[f][r][k-w[l]];
		}
	}
	int f = n%2;
	rep(r,0,1<<n){
		rep(k,1,101) dp[f][r][k] += dp[f][r][k-1];
	}
	rep(_,0,q){
		string t;
		int k;
		cin >> t >> k;
		int r = 0;
		trav(c, t) r = r*2 + (c-'0');
		cout << dp[f][r][k] << endl;
	}
}