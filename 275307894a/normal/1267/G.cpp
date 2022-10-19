#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=1e2+5,M=1e4+5,K=2e3+5,mod=1e9+7,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,m,k,y,z,C[N],Fl[N][M];db dp[N][M],x,g[N],Ans,ToT,P[N][N];
int main(){
	int i,j,h;scanf("%d%lf",&n,&x);x/=2.0;for(i=1;i<=n;i++) scanf("%d",&C[i]),m+=C[i];for(i=0;i<=n;i++) for(P[i][0]=j=1;j<=n;j++) P[i][j]=P[i-1][j]+P[i-1][j-1];
	dp[0][0]=1;for(i=1;i<=n;i++) for(j=n;j;j--) for(h=C[i];h<=m;h++) dp[j][h]+=dp[j-1][h-C[i]];
	for(i=0;i<n;i++) for(j=0;j<=m;j++) Ans+=dp[i][j]/P[n][i]*min((m-j)*1.0/(n-i),x+x/(1-i*1.0/n));printf("%.9lf\n",Ans);
}