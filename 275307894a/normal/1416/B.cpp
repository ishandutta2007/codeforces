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
#define M (500000+5)
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
int n,m,k,T,X[N+5],Y[N+5],Z[N+5],H,A[N+5],La;ll Sum;
I void Solve(){
	RI i;Sum=0;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Sum+=A[i];
	H=0;if(Sum%n) {printf("-1\n");return;}for(i=2;i<=n;i++) X[++H]=1,Y[H]=i,Z[H]=(i-A[i]%i)%i,A[i]+=Z[H],X[++H]=i,Y[H]=1,Z[H]=A[i]/i;
	Sum/=n;for(i=2;i<=n;i++) X[++H]=1,Y[H]=i,Z[H]=Sum;printf("%d\n",H);for(i=1;i<=H;i++) printf("%d %d %d\n",X[i],Y[i],Z[i]);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}