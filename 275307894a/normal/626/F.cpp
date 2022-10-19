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
#define N 200
#define K 1000
#define mod 1000000007
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
int n,m,k,Ne,La,x,y,A[N+5];ll dp[2][N+5][K+5],ToT;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);sort(A+1,A+n+1);
	dp[n&1][1][0]=dp[n&1][0][0]=1;for(i=n-1;i;i--){
		Ne=i&1;La=Ne^1;Me(dp[Ne],0);for(j=0;j<=n;j++){
			for(h=0;h<=k;h++){
				x=h+j*A[i];if(j&&x-A[i]>=(j-1)*A[i+1]&&x-A[i]<=(j-1)*A[i+1]+k) dp[Ne][j][h]+=dp[La][j-1][x-A[i]-(j-1)*A[i+1]];
				if(x+A[i]>=(j+1)*A[i+1]&&x+A[i]<=(j+1)*A[i+1]+k)dp[Ne][j][h]+=(j+1)*dp[La][j+1][x+A[i]-(j+1)*A[i+1]];
				if(x>=j*A[i+1]&&x<=j*A[i+1]+k)dp[Ne][j][h]+=(j+1)*dp[La][j][x-j*A[i+1]];dp[Ne][j][h]%=mod;
			}
		}
	}for(i=0;i<=k;i++) ToT+=dp[1][0][i];printf("%lld\n",ToT%mod);
}////