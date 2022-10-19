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
#define N 1000
#define K 100000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,k,Maxn,R,A[N+5],Ne,La;ll Ans[K+5],Q[N+5],dp[2][N+5],ToT;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);sort(A+1,A+n+1);Maxn=A[n];
	for(i=1;i<=Maxn/(k-1);i++){
		Me(dp,0);dp[0][0]=1;for(j=1;j<=k;j++){
			Ne=j&1;La=Ne^1;dp[Ne][0]=0;for(Q[0]=dp[La][0],h=1;h<=n;h++) Q[h]=Q[h-1]+dp[La][h]-(Q[h-1]+dp[La][h]>mod?mod:0);
			for(R=0,h=1;h<=n;h++){while(R<n&&A[R+1]+i<=A[h]) R++;dp[Ne][h]=Q[R];}
		}for(j=1;j<=n;j++) Ans[i]+=dp[k&1][j];
	}for(i=1;i<=Maxn/(k-1);i++) ToT+=i*(Ans[i]-Ans[i+1])%mod;printf("%lld\n",ToT%mod);
}