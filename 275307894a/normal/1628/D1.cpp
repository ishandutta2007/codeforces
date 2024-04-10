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
#define N (2000+5)
#define M (N*200)+5
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
using namespace std;const ll Inv2=(mod+1)/2;
int n,m,k,T;ll dp[N+5][N+5];
I void Solve(){
	RI i,j;scanf("%d%d%d",&n,&m,&k);for(i=0;i<=n;i++)for(j=0;j<=m;j++) dp[i][j]=0;
	dp[1][0]=0;dp[1][1]=k;dp[1][2]=3ll*k%mod;for(i=2;i<=n;i++){
		for(j=1;j<=min(i,m);j++) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*Inv2%mod;dp[i][min(i,m)+1]=(dp[i][min(i,m)]+1ll*k*2)%mod;
	}
	printf("%lld\n",dp[n][m]);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--) Solve();
}