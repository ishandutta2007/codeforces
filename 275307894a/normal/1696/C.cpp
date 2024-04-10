#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int x,y,T,R,n,m,A[N],B[N],k,H;ll C[N],D[N];
I void Solve(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);scanf("%d",&k);for(i=1;i<=k;i++) scanf("%d",&B[i]);
	for(i=1;i<=H;i++) C[i]=D[i]=0;H=0;for(i=1;i<=n;i++) {x=A[i];while(x%m==0) x/=m;x^C[H]?(C[++H]=x,D[H]=A[i]/x):(D[H]+=A[i]/x);}
	R=1;for(i=1;i<=k;i++){
		x=B[i];while(x%m==0) x/=m;y=B[i]/x;while(y){
			if(R>H||x^C[R]) {puts("No");return;}if(D[R]>y) {D[R]-=y;y=0;break;}else y-=D[R],R++;
		}
	}if(R!=H+1)puts("No");else puts("Yes");
}
int main(){
//	//freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}