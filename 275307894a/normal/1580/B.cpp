#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100+5)
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
using namespace std;
int n,m,k,p,Ne,La;ll dp[2][N][N],C[N][N],frc[N];
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h,x,y;scanf("%d%d%d%d",&n,&m,&k,&p);for(i=0;i<=n;i++) for(C[i][0]=j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;for(frc[0]=i=1;i<=n;i++) frc[i]=frc[i-1]*i%p;
	for(i=0;i<=n;i++) dp[0][i][0]=frc[i];
	for(j=1;j<=m;j++){Ne=j&1;La=Ne^1;Me(dp[Ne],0);dp[Ne][0][0]=1;
		for(i=1;i<=n;i++)for(h=0;h<=(j<=i?min(k,i/2+1):0);h++){
			for(x=1;x<=i;x++) for(y=0;y<=h-(j==1);y++) dp[La][x-1][y]&&dp[La][i-x][h-y-(j==1)]&&(dp[Ne][i][h]=(dp[Ne][i][h]+dp[La][x-1][y]*dp[La][i-x][h-y-(j==1)]%p*C[i-1][x-1])%p);
		}
	}printf("%lld\n",dp[m&1][n][k]);
}