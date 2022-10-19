#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100
#define M 200000
#define mod 998244353
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,T,flag,A[N+5],B[N+5],dp[N+5][N+5];
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&T);while(T--){
		scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),A[i]+=A[i-1];scanf("%d",&m);for(i=1;i<=m;i++) scanf("%d",&B[i]),B[i]+=B[i-1];
		Me(dp,-0x3f);dp[0][0]=0;for(i=0;i<=n;i++){
			for(j=0;j<=m;j++) {
				i&&(dp[i][j]=max(dp[i][j],max(dp[i-1][j],A[i]+B[j])));
				j&&(dp[i][j]=max(dp[i][j],max(dp[i][j-1],A[i]+B[j])));
			}
		}printf("%d\n",dp[n][m]);
	}
}