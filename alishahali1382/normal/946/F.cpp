#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][MAXN][MAXN][4];
string s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>x>>s;
	for (int j=0; j<=n; j++) dp[0][j][j][1]=dp[1][j][j][1]=dp[0][j][j][2]=dp[1][j][j][2]=dp[0][j][j][3]=dp[1][j][j][3]=2;
	for (int j=0; j<=n; j++) dp[0][j][j][0]=dp[1][j][j][0]=1;
	for (int i=0; i<n; i++) dp[s[i]-'0'][i][i+1][0]=dp[s[i]-'0'][i][i+1][1]=dp[s[i]-'0'][i][i+1][2]=dp[s[i]-'0'][i][i+1][3]=1;
	for (int i=2; i<=x; i++){
		for (int j=0; j<=n; j++) dp[i][j][j][1]=dp[i][j][j][2]=dp[i][j][j][3]=dp[i-1][j][j][3]*dp[i-2][j][j][3]%mod;
		for (int j=0; j<=n; j++) dp[i][j][j][0]=1;
		for (int l=n; l>=0; l--) for (int r=l+1; r<=n; r++){
			for (int k=l+1; k<r; k++){
				dp[i][l][r][0]+=dp[i-1][l][k][0]*dp[i-2][k][r][0]%mod;
				dp[i][l][r][1]+=dp[i-1][l][k][0]*dp[i-2][k][r][1]%mod;
				dp[i][l][r][2]+=dp[i-1][l][k][2]*dp[i-2][k][r][0]%mod;
				dp[i][l][r][3]+=dp[i-1][l][k][2]*dp[i-2][k][r][1]%mod;
			}
			// k=l
			dp[i][l][r][0]+=dp[i-2][l][r][0];
			dp[i][l][r][1]+=dp[i-2][l][r][1];
			dp[i][l][r][2]+=dp[i-1][l][l][2]*dp[i-2][l][r][2]%mod;
			dp[i][l][r][3]+=dp[i-1][l][l][3]*dp[i-2][l][r][3]%mod;
			
			// k=r
			dp[i][l][r][0]+=dp[i-1][l][r][0];
			dp[i][l][r][1]+=dp[i-1][l][r][1]*dp[i-2][r][r][1]%mod;
			dp[i][l][r][2]+=dp[i-1][l][r][2];
			dp[i][l][r][3]+=dp[i-1][l][r][3]*dp[i-2][r][r][3]%mod;
			
			dp[i][l][r][0]%=mod;
			dp[i][l][r][1]%=mod;
			dp[i][l][r][2]%=mod;
			dp[i][l][r][3]%=mod;
		}
	}
	
	cout<<dp[x][0][n][3]<<'\n';
	
	return 0;
}