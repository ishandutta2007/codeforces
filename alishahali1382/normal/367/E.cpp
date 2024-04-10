#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>x;
	if (n>m) kill(0)
	
	ll dp[m+1][n+1][n+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0]=1;
	for (int i=1; i<=m; i++){
		if (i<x) dp[i][0][0]=1;
		for (int j=1; j<=n; j++) for (int k=0; k<=j; k++){
			if (i!=x) dp[i][j][k]=dp[i-1][j][k];
			if (k) dp[i][j][k]+=dp[i-1][j-1][k-1];
			if (k && i!=x) dp[i][j][k]+=dp[i-1][j][k-1];
			dp[i][j][k]+=dp[i-1][j-1][k];
			dp[i][j][k]%=mod;
		}
	}
	ans=dp[m][n][n];
	for (int i=1; i<=n; i++) ans=ans*i%mod;
	cout<<ans<<'\n';
	
	return 0;
}