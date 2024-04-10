#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,f[10039],ans=1e10;
int main(){
	register int i;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
	for(i=1;i<=x*y;i++) f[i]=min(f[i-1]+m,f[i-x]+n);
	for(i=x*y-k;i<=x*y;i++) ans=min(ans,f[i]);
	printf("%d\n",ans);
}