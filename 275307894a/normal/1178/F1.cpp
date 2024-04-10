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
#define K 1000
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
int n,m,k,Minn,Id,A[N+5];ll F[N+5][N+5],T1,T2;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) F[i][i]=1,scanf("%d",&A[i]);for(i=1;i<=n+1;i++)F[i][i-1]=1;
	for(i=n;i;i--){
		for(j=i+1;j<=n;j++) {
			Minn=1e9;for(h=i;h<=j;h++) Minn=min(Minn,A[h]);for(h=i;h<=j;h++) if(A[h]==Minn){Id=h;break;}
			T1=T2=0;for(h=i;h<=Id;h++) T1=(F[i][h-1]*F[h][Id-1]+T1)%mod;for(h=Id;h<=j;h++) T2=(F[Id+1][h]*F[h+1][j]+T2)%mod;F[i][j]=T1*T2%mod;//printf("%lld %lld %d %d\n",T1,T2,i,j);
		}
	}printf("%lld\n",F[1][n]);
}