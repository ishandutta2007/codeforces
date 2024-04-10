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
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int dp[n+1][a][b][2*n+1], lst[n+1][a][b][2*n+1]; 
	rep(i, n+1) rep(j, a) rep(l, b) rep(d, 2*n+1) {
		dp[i][j][l][d]=0; lst[i][j][l][d]=0;
	}
	dp[0][0][0][n]=1;
	rep(i, n) {
		int p=s[i]-'0';
		rep(j, a) rep(l, b) rep(d, 2*n+1) if(dp[i][j][l][d]) {
			if(d<2*n) {
				dp[i+1][(10*j+p)%a][l][d+1]=1;
				lst[i+1][(10*j+p)%a][l][d+1]=j+1;
			}
			if(d>0) {
				dp[i+1][j][(10*l+p)%b][d-1]=1;
				lst[i+1][j][(10*l+p)%b][d-1]=-l-1;
			}
		}
	}
	string ans="";
	int akta=0, aktb=0, aktd=INF;
	rep(i, n) {
		if(dp[n][0][0][n+i]) {
			aktd=n+i;
			break;
		}
		if(dp[n][0][0][n-i]) {
			aktd=n-i;
			break;
		}
	}
	if(aktd==INF) {
		cout << -1 << '\n';
		return;
	}
	for(int i=n; i; --i) {
		if(lst[i][akta][aktb][aktd]>0) {
			ans+="R";
			akta=lst[i][akta][aktb][aktd]-1;
			--aktd;
		} else {
			ans+="B";
			aktb=-lst[i][akta][aktb][aktd]-1;
			++aktd;
		}
	}
	reverse(all(ans));
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}