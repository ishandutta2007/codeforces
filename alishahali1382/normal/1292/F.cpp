#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=65, K=16, mod=1000000007;

ll n, m, k, u, v, x, y, t, a, b, ans=1, ted;
int A[N], B[N], src[N], vec[N], adj[N];
ll dp[N][1<<K], C[N][N];

void dfs(int v){
	A[v]=0;
	if (B[v]) vec[m++]=v;
	else src[k++]=v;
	for (int u=1; u<N; u++) if (A[u] && (u%v==0 || v%u==0)) dfs(u);
}

int main(){
	for (int i=0; i<N; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	cin>>n;
	while (n--) cin>>x, A[x]=1;
	for (int i=1; i<N; i++) if (A[i]) for (int j=i+i; j<N; j+=i) B[j]=1;
	for (int i=1; i<N; i++) if (A[i]){
		m=k=0;
		dfs(i);
		if (!m) continue ;
		m--;
		for (int t=0; t<=m; t++) for (int mask=0; mask<(1<<k); mask++) dp[t][mask]=0;
		for (int j=0; j<=m; j++){
			adj[j]=0;
			for (int a=0; a<k; a++) if (vec[j]%src[a]==0) adj[j]|=(1<<a);
			dp[0][adj[j]]++;
		}
		for (int j=0; j<m; j++) for (int mask=1; mask<(1<<k); mask++){
			dp[j][mask]%=mod;
			for (int x=0; x<=m; x++) if (mask&adj[x]) dp[j+1][mask|adj[x]]+=dp[j][mask];
			dp[j+1][mask]-=dp[j][mask]*(j+1);
		}
		ans=ans*dp[m][(1<<k)-1]%mod*C[ted+=m][m]%mod;
	}
	cout<<ans<<"\n";
	
	return 0;
}