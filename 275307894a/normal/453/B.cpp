#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (16)
#define M (100+5)
#define K (20+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
using namespace std;
int n,dp[M][(1<<N)+5],Ans=1e9,La[M][(1<<N)+5],W[M][(1<<N)+5],Bh,B[N+5],A[N+5],C[M],ph=16,pr[N+5]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
I void calc(int x,int op){if(!op) return;calc(La[op][x],op-1);printf("%d ",W[op][x]);}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=0;i<59;i++) for(j=0;j<ph;j++) C[i]|=(i%pr[j]==0)<<j; 
	Me(dp,0x3f);dp[0][0]=0;for(i=1;i<=n;i++) for(j=0;j<(1<<ph);j++)for(h=1;h<59;h++) ((j&C[h])==C[h])&&dp[i][j]>dp[i-1][j^C[h]]+abs(A[i]-h)&&(dp[i][j]=dp[i-1][j^C[h]]+abs(A[i]-h),La[i][j]=j^C[h],W[i][j]=h);
	for(i=0;i<(1<<ph);i++)Ans=min(Ans,dp[n][i]);for(i=0;i<(1<<ph);i++) if(dp[n][i]==Ans){calc(i,n);return 0;}
}