#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1005;
int n,a[N],T,f[N][N],l[N][N],r[N][N],m;
il int Max(ct p,ct q){return p>q?p:q;}
int main(){
	scanf("%d%d",&n,&m);it i,j,x,y;
	for(i=1;i<=n;++i){
		scanf("%d",&T);
		while(T--) for(scanf("%d%d",&x,&y),j=x;j<=y;++j) l[i][j]=x,r[i][j]=y;
	}
	for(it l=m,r,k;l;--l)
		for(r=l;r<=m;++r)
			for(k=l;k<=r;++k){
				for(i=1,x=0;i<=n;++i) x+=(::l[i][k]>=l&&::r[i][k]<=r);
				f[l][r]=Max(f[l][r],f[l][k-1]+f[k+1][r]+x*x);
			}
	printf("%d",f[1][m]);
	return 0;
}