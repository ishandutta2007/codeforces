#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1500+5)
#define M ((1<<16)+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> S[N*2],P[N];ll dp[N*2][N],G[N];
int fa[N],cnt,n,m,k,x,y,z,Si[N*2],F1[N],X[N*N],Y[N*N];
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
I void dfs(int x){
	Si[x]=0;dp[x][0]=1;int i,j;for(int v:S[x]){
		dfs(v);Mc(G,dp[x]);Me(dp[x],0);for(i=0;i<=Si[x];i++){
			for(j=0;j<=Si[v];j++) dp[x][i+j]=(G[i]*dp[v][j]+dp[x][i+j])%mod;
		}Si[x]+=Si[v];
	}!S[x].size()&&(Si[x]=1,dp[x][0]=0);dp[x][1]=1;
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);cnt=n;for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&x),X[x]=i,Y[x]=j;
	for(i=1;i<=n;i++) fa[i]=i,Si[i]=F1[i]=1,P[i].PB(i);for(i=1;i<=n*n;i++){
		if(GF(X[i])^GF(Y[i])){x=GF(X[i]);y=GF(Y[i]);fa[x]=y;for(int j:P[x]) P[y].PB(j);Si[y]+=Si[x];F1[y]+=F1[x];}
		x=GF(X[i]);F1[x]++;if(F1[x]==Si[x]*(Si[x]+1)/2) {++cnt;for(int j:P[x]) S[cnt].PB(j);P[x].clear();P[x].PB(cnt);}
	}dfs(cnt);for(i=1;i<=n;i++) printf("%lld ",dp[cnt][i]);
}