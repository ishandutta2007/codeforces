#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M (100+5)
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
using namespace std;
int n,k,p,A[N],Q[N];
namespace Solve1{
	int dp[M][M*M],Fl[M];
	I void calc(){
		int i,j,h;Me(dp,0x3f);dp[0][0]=0;
		for(i=1;i<=k;i++){
			Me(Fl,0x3f);for(j=0;j<=n;j++){for(h=0;h<p;h++) dp[i][j]=min(dp[i][j],Fl[h]+(Q[j]-h+p)%p);Fl[Q[j]]=min(Fl[Q[j]],dp[i-1][j]);}
		}printf("%d\n",dp[k][n]);
	}
}
namespace Solve2{
	int dp[N],Fl[M];
	I void calc(){
		int i,j,h;Me(dp,-0x3f);dp[0]=0;Fl[0]=0;for(i=1;i<=n;i++){
			for(j=0;j<=Q[i];j++) dp[i]=max(dp[i],Fl[j]+1);Fl[Q[i]]=max(Fl[Q[i]],dp[i]); 
		}printf("%d\n",dp[n]>=k?Q[n]:Q[n]+p);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d%d%d",&n,&k,&p);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) Q[i]=(Q[i-1]+A[i])%p;
	if(n<=k*p) Solve1::calc();else Solve2::calc();
}