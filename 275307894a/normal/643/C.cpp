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
#define N 200000
#define K 50
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5) 
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Ne,La,A[N+5],Q[N+5],H,T;db Q1[N+5],Q2[N+5],Q3[N+5],dp[2][N+5];
I db slope(int j,int h){return (dp[La][h-1]+Q1[h-1]*Q2[h-1]-Q3[h-1]-dp[La][j-1]-Q1[j-1]*Q2[j-1]+Q3[j-1])/(Q1[h-1]-Q1[j-1]);}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]),Q1[i]=Q1[i-1]+A[i],Q2[i]=Q2[i-1]+1.0/A[i],Q3[i]=Q1[i]/A[i]+Q3[i-1];
	for(i=1;i<=n;i++)dp[0][i]=1e18;dp[0][0]=0;for(i=1;i<=k;i++){
		Ne=i&1;La=Ne^1;for(j=0;j<=n;j++) dp[Ne][j]=1e18;H=1;T=0; 
		for(j=1;j<=n;j++){
			while(H<T&&slope(Q[T-1],Q[T])>slope(Q[T-1],j))T--;Q[++T]=j;while(H<T&&slope(Q[H],Q[H+1])<Q2[j]) H++;dp[Ne][j]=dp[La][Q[H]-1]+Q3[j]-Q3[Q[H]-1]-Q1[Q[H]-1]*(Q2[j]-Q2[Q[H]-1]);
		}
	}printf("%.5lf\n",dp[k&1][n]);
}