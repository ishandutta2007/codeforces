#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1005,M=1000005;
int n,m,a[N][N],b[N],c[N],X[M],Y[M],o[N][N];
bool f[M],g[M];
il int Max(ct p,ct q){return p>q?p:q;}
int main(){
	scanf("%d%d",&n,&m);it i,j,x=0,y=0,top1=1,top=0;
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) scanf("%d",&a[i][j]),b[i]=Max(b[i],a[i][j]),c[j]=Max(c[j],a[i][j]);
	for(i=1;i<=n;++i) f[b[i]]=1;
	for(i=1;i<=m;++i) g[c[i]]=1;
	for(i=n*m;i;--i){
		x+=f[i],y+=g[i],f[i]||g[i]?o[x][y]=i:(o[X[top1]][Y[top1]]=i,++top1);
		if(f[i]) for(j=y-1;j;--j) X[++top]=x,Y[top]=j;
		if(g[i]) for(j=x-1;j;--j) X[++top]=j,Y[top]=y;
	}
	for(i=1;i<=n;puts(""),++i) for(j=1;j<=m;++j) printf("%d ",o[i][j]);
	return 0;
}