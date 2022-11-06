#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

char dp[51][51][51][51];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> ss(n);
	trav(s, ss) cin >> s;

	vector<vi> pre(n+1, vi(n+1));
	rep(i,0,n) rep(j,0,n)
		pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j]
				+ (ss[i][j]=='#');

	rep(d,0,n+1) rep(e,0,n+1)
		rep(j,d,n+1) rep(y,e,n+1){
		int i = j-d, x = y-e;
		if(pre[j][y]-pre[i][y]-pre[j][x]+pre[i][x] == 0){
			dp[i][j][x][y] = 0;
		}
		else {
			dp[i][j][x][y] = (char)max(j-i, y-x);
			rep(k,i+1,j){
				dp[i][j][x][y] = min(dp[i][j][x][y],
					char(dp[i][k][x][y] + dp[k][j][x][y]));
			}
			rep(k,x+1,y){
				dp[i][j][x][y] = min(dp[i][j][x][y],
					char(dp[i][j][x][k] + dp[i][j][k][y]));
			}
		}
	}
	cout << (int)dp[0][n][0][n] << endl;
}