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
const int mod = 998244353;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll dp[MAXN][201][2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]!=-1) A[i]=201-A[i];
	}
	if (A[1]==-1) for (int i=1; i<=200; i++) dp[1][i][0]=i;
	else for (int i=A[1]; i<=200; i++) dp[1][i][0]=1;
	for (int i=2; i<=n; i++){
		for (int j=1; j<=200; j++){
			dp[i][j][0]=(dp[i-1][200][0]-dp[i-1][j][0]) + (dp[i-1][200][1]-dp[i-1][j][1]);
			dp[i][j][1]=dp[i-1][j-1][1] + (dp[i-1][j][0]-dp[i-1][j-1][0]) + (dp[i-1][j][1]-dp[i-1][j-1][1]);
			
			
			//if (i==3 && j==1) debug(dp[3][1][1])
			
			if (A[i]!=-1 && A[i]!=j) dp[i][j][0]=dp[i][j][1]=0;
			
			dp[i][j][0]=(dp[i][j-1][0]+dp[i][j][0])%mod;
			dp[i][j][1]=(dp[i][j-1][1]+dp[i][j][1])%mod;
		}
	}
	cout<<(dp[n][200][1]+mod)%mod<<'\n';
	
	debug(dp[2][200][0])
	debug(dp[2][200][1])
	
	/*
	debug(dp[2][0][1])
	debug((dp[2][1][0]-dp[2][0][0]))
	*/
	return 0;
}
/*
3
2 1 1
*/