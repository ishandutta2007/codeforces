#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int N=105;

ll n, m, k, u, v, x, y, t, a, b, ans, mod;
ll dp[N][N][N];
ll C[N][N], F[N];
ll sum[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k>>mod;
	if (mod==1) kill(0)
	if (m==1) kill((k==1))
	F[0]=1;
	for (int i=1; i<N; i++) F[i]=F[i-1]*i%mod;
	for (int i=0; i<N; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	dp[1][1][1]=1;
	for (int h=2; h<=n; h++) dp[1][h][0]=1;
	for (int i=2; i<=n; i++){
		dp[i][1][1]=F[i];
		for (int h=i+1; h<=n; h++) dp[i][h][0]=F[i];
		for (int h=2; h<=i; h++){
			for (int t=0; t<=i; t++) dp[i][h][t]=2ll*dp[i-1][h-1][t]%mod;
			for (int sl=1; sl<i-1; sl++){
				int sr=i-sl-1;
				memset(sum, 0, sizeof(sum));
				for (int tl=0; tl<=i; tl++){
					if (!dp[sl][h-1][tl]) continue ;
					for (int tr=0; tl+tr<=i; tr++){
						sum[tl+tr]=(sum[tl+tr] + dp[sl][h-1][tl]*dp[sr][h-1][tr])%mod;
					}
				}
				for (int t=0; t<=i; t++){
//					if (i==2 && h==2 && t==1) debug(sum[t])
					dp[i][h][t]=(dp[i][h][t] + sum[t]*C[i-1][sl])%mod;
				}
			}
		}
	}
//	debug(dp[2][2][1])
	cout<<dp[n][m][k]<<"\n";
	
	return 0;
}