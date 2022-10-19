#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (3000+5)
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
int T,n,A[N],Fs[N],Q[N][N],Ns;
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) for(scanf("%d",&A[i]),j=1;j<=n+1;j++) Q[i][j]=1e9;
	Q[n][n+1]=0;for(i=n-1;i;i--){
		for(j=1;j<=n;j++) Fs[j]=0;
		Ns=0;for(j=1;j<=A[i];j++) Q[i][i+j]=Q[i+j][i+A[i]+1]+Ns,A[i+j]&&(Fs[i+j+A[i+j]]++,Ns++),Ns-=Fs[i+j];
		for(j=A[i];~j;j--) Q[i][i+j]=min(Q[i][i+j],Q[i][i+j+1]);
	}printf("%d\n",Q[1][1]);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}