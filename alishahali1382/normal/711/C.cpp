#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=500000000000000010LL;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 110;

int n, m, k;
int c[MAXN];
int p[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN]; // dp[i][j][x] ==> i trees && c[i]=j && beuty k

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0; i<n; i++) cin>>c[i];
	for (int i=0; i<n; i++){
		for (int j=1; j<=m; j++){
			cin>>p[i][j];
		}
	}
	memset(dp, inf, sizeof(dp));
	if (c[0]){
		dp[0][c[0]][1]=0;
	}
	else{
		for (int j=1; j<=m; j++){
			dp[0][j][1]=p[0][j];
		}
	}
	for (int i=1; i<n; i++){
		if (c[i]){
			for (int x=1; x<=k; x++){
				dp[i][c[i]][x]=dp[i-1][c[i]][x];
				for (int j=1; j<=m; j++){
					if (j==c[i]) continue ;
					dp[i][c[i]][x]=min(dp[i][c[i]][x], dp[i-1][j][x-1]);
				}
			}
		}
		else{
			for (int j=1; j<=m; j++){
				for (int x=1; x<=k; x++){
					dp[i][j][x]=dp[i-1][j][x] + p[i][j];
					for (int jj=1; jj<=m; jj++){
						if (j==jj) continue ;
						dp[i][j][x]=min(dp[i][j][x], dp[i-1][jj][x-1] + p[i][j]);
					}
				}
			}
		}
	}
	ll ans=inf;
	for (int i=1; i<=m; i++) ans=min(ans, dp[n-1][i][k]);
	if (ans==inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}