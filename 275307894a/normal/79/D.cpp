#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N (10000+5)
#define M (1<<20)
#define mod 1000000007
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
int n,m,k,x,H,W[30][30],G[M+5],A[N+5],B[105],F[N+5],dp[M+5];queue<int> Q;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d%d",&n,&k,&m);for(i=1;i<=k;i++) scanf("%d",&x),A[H]^x?(A[H++]=x):(H--),A[H++]=x+1;H&1&&(A[H++]=n+1);for(i=1;i<=m;i++) scanf("%d",&B[i]);
	for(i=0;i<H;i++){Me(F,0x3f);F[A[i]]=0;Q.push(A[i]);
		while(!Q.empty())for(x=Q.front(),Q.pop(),j=1;j<=m;j++)x+B[j]<=n+1&&F[x+B[j]]>F[x]+1&&(Q.push(x+B[j]),F[x+B[j]]=F[x]+1),x-B[j]>0&&F[x-B[j]]>F[x]+1&&(Q.push(x-B[j]),F[x-B[j]]=F[x]+1);
		for(j=0;j<H;j++)W[i][j]=F[A[j]];
	}
	Me(dp,0x3f);dp[0]=0;for(i=1;i<(1<<H);i++){
		G[i]=G[i>>1]+(i&1);if(G[i]&1) continue;for(j=0;j<H;j++){if(!(i>>j&1)) continue;
			for(h=j+1;h<H;h++)i>>h&1&&(dp[i]=min(dp[i],dp[i^(1<<j)^(1<<h)]+W[j][h]));
		}
	}printf("%d\n",dp[(1<<H)-1]>1e9?-1:dp[(1<<H)-1]);
}