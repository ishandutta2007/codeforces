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

const int inf = 100000;

int dp[80][80][80];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i,0,80) rep(j,0,80) rep(k,0,80) dp[i][j][k] = -1;

	int n,k,m;
	cin >> n >> k >> m;

	vector<vi> di(n, vi(n, inf));
	rep(_,0,m){
		int u,v,c;
		cin >> u >> v >> c;
		--u, --v;
		di[u][v] = min(di[u][v], c);
	}

	function<int(int,int,int)> calc = [&](int a, int b, int c){
		if(c == 0) return 0;
		if(dp[a][b][c] == -1){
			int res = inf;
			if(b < a){
				rep(d,b,a) res = min(res,
					di[a][d] + min(calc(d,a-1,c-1), calc(d,b,c-1)));
			} else {
				rep(d,a+1,b+1) res = min(res,
					di[a][d] + min(calc(d,a+1,c-1), calc(d,b,c-1)));
			}
			dp[a][b][c] = res;
		}
		return dp[a][b][c];
	};
	int ans = inf;
	rep(i,0,n){
		ans = min(ans, calc(i,0,k-1));
		ans = min(ans, calc(i,n-1,k-1));
	}
	if(ans == inf){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}