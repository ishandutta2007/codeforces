#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#undef continue
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=5e3+5,M=1<<18|5,K=200+5,mod=998244353,Mod=mod-1;const db eps=1e-5;
int n,m,k,x,y,z,Ct,A[N],C[N],B[N],W[N],dp[N][N]; vector<int> S[N];
int main(){
	//freopen("1.in","r",stdin); 
	int i,j;scanf("%d%d%d",&n,&m,&k);Ct=k;for(i=1;i<=n;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]),Ct+=B[i];
	for(i=1;i<=m;i++) scanf("%d%d",&x,&y),W[y]=max(W[y],x); for(i=1;i<=n;i++) W[i]&&(S[W[i]].PB(i),0);
	Me(dp,-0x3f);dp[0][k]=0;for(i=1;i<=n;i++){
		for(j=A[i];j<=Ct-B[i];j++) dp[i][j+B[i]]=dp[i-1][j];
		if(!W[i]) for(j=0;j<Ct;j++) dp[i][j]=max(dp[i][j],dp[i][j+1]+C[i]);
		for(int d:S[i]) for(j=0;j<Ct;j++) dp[i][j]=max(dp[i][j],dp[i][j+1]+C[d]);
	}int Ans=-1e9;for(i=0;i<=Ct;i++) Ans=max(Ans,dp[n][i]);printf("%d\n",max(Ans,-1));
}