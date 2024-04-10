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
#define N (200000+5)
#define M (N*50+5)
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
using namespace std;
int T,n,A[N+5],F[N+5],x,y;
I void Solve(){
	RI i,j
	;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	for(i=0;i<=n;i++) F[i]=0;for(i=0;i<30;i++){
		x=0;for(j=1;j<=n;j++)x+=(A[j]>>i)&1;F[x]++;
	}
	for(i=1;i<=n;i++) {
		y=30;for(j=0;j<=n;j+=i)  y-=F[j];if(!y) printf("%d ",i);
	}puts("");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}