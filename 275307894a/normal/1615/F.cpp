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
#define N 2000
#define M 500
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,n,L[N+5],R[N+5],x,y;ll dp[N+5][N+5],F[N+5][N+5],Q1[N+5][N+5],Q2[N+5][N+5];char A[N+5],B[N+5];
I ll calc1(int x,int y,int l,int r){!x&&(x++);!l&&(l++);return Q1[y][r]-Q1[y][l-1]-Q1[x-1][r]+Q1[x-1][l-1];}
I ll calc2(int x,int y,int l,int r){!x&&(x++);!l&&(l++);return Q2[y][r]-Q2[y][l-1]-Q2[x-1][r]+Q2[x-1][l-1];}
I void Solve(){
	RI i,j;scanf("%d%s%s",&n,A+1,B+1);for(i=0;i<=n+1;i++) for(j=0;j<=n+1;j++) dp[i][j]=F[i][j]=Q1[i][j]=Q2[i][j]=0;
	A[0]=B[0]=A[n+1]=B[n+1]=0;for(i=1;i<=n;i+=2) A[i]^'?'&&(A[i]^=1),B[i]^'?'&&(B[i]^=1);
	for(i=1;i<=n+1;i++) L[i]=(A[i]^'1'?L[i-1]:i),R[i]=(B[i]^'1'?R[i-1]:i);
	F[0][0]=1;for(i=1;i<=n+1;i++){
		for(j=1;j<=n+1;j++){
			Q1[i][j]=Q1[i-1][j]+Q1[i][j-1]-Q1[i-1][j-1];Q2[i][j]=Q2[i-1][j]+Q2[i][j-1]-Q2[i-1][j-1];if(A[i]=='0'||B[j]=='0') continue;
			x=L[i-1];y=R[j-1];F[i][j]=(calc1(x,i-1,y,j-1)+F[x][y])%mod;dp[i][j]=(F[i][j]*abs(i-j)+calc2(x,i-1,y,j-1)+dp[x][y])%mod;
			if(A[i]=='?'||B[j]=='?')Q1[i][j]+=F[i][j],Q2[i][j]+=dp[i][j];
		}
	}printf("%lld\n",dp[n+1][n+1]);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}