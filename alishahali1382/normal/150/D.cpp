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
const int MAXN = 156;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int ans[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
string s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	cin>>s;
	s="."+s;
	memset(dp, -63, sizeof(dp));
	for (int l=0; l<=n+1; l++) for (int r=0; r<l; r++) dp[l][r][0]=0;
	for (int i=0; i<=n+1; i++) dp[i][i][1]=0;
	for (int l=n; l; l--) for (int r=l; r<=n; r++){
		for (int k=l; k<=r; k++) dp[l][r][1]=max(dp[l][r][1], dp[l][k-1][0] + dp[k+1][r][0]);
		for (int len=2; len<=r-l+1; len++){
			for (int k=l+1; k<=r; k++) if (s[l]==s[k]) dp[l][r][len]=max(dp[l][r][len], dp[l+1][k-1][len-2] + dp[k+1][r][0]);
			for (int k=l; k<=r; k++) dp[l][r][len]=max(dp[l][r][len], max(dp[l][k][len]+dp[k+1][r][0], dp[l][k][0]+dp[k+1][r][len]));
		}
		for (int len=1; len<=r-l+1; len++) if (A[len]>=0) dp[l][r][0]=max(dp[l][r][0], dp[l][r][len] + A[len]);
		ans[l][r]=max(dp[l][r][0], 0);
		for (int k=l; k<=r; k++) ans[l][r]=max(ans[l][r], dp[l][k-1][0] + ans[k+1][r]);
	}
	//for (int l=1; l<=n; l++) for (int r=1; r<=n; r++) cerr<<ans[l][r]<<" \n"[r==n];
	cout<<ans[1][n]<<'\n';
	
	return 0;
}