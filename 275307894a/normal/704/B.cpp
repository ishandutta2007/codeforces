#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (5000+5)
#define M ((1<<14)+5)
#define K (700+5)
#define mod 64123
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,s,e,A[N],B[N],C[N],D[N],p[N];ll f[N],g[N];
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d%d",&n,&s,&e);for(i=1;i<=n;i++) scanf("%d",&p[i]);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]);
	for(i=1;i<=n;i++) scanf("%d",&C[i]);for(i=1;i<=n;i++) scanf("%d",&D[i]);Me(f,0x3f);f[0]=0;for(i=1;i<=n;i++){
		Mc(g,f);Me(f,0x3f);if(i==s) for(j=0;j<i;j++) j&&(f[j]=min(f[j],g[j]+p[i]+C[i])),f[j+1]=min(f[j+1],g[j]-p[i]+D[i]);
		else if(i==e) for(j=0;j<i;j++) j&&(f[j]=min(f[j],g[j]+p[i]+A[i])),f[j+1]=min(f[j+1],g[j]-p[i]+B[i]);
		else for(j=0;j<i;j++) (!j||2*j-(i>s)-(i>e))&&(f[j+1]=min(f[j+1],g[j]-2*p[i]+D[i]+B[i])),j>=2&&(f[j-1]=min(f[j-1],g[j]+2*p[i]+A[i]+C[i])),j-(i>s)>0&&(f[j]=min(f[j],g[j]+B[i]+C[i])),j-(i>e)>0&&(f[j]=min(f[j],g[j]+A[i]+D[i]));
	}printf("%lld\n",f[1]);
}