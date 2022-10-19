#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a1[2039],a2[2039],b1[2039],b2[2039],xs[1000039],ys[1000039],ans=1e9;
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a1[i],&a2[i]);
	for(i=1;i<=m;i++) scanf("%d%d",&b1[i],&b2[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a1[i]<=b1[j]&&a2[i]<=b2[j]){
				xs[b1[j]-a1[i]]=max(b2[j]-a2[i]+1,xs[b1[j]-a1[i]]);
				ys[b2[j]-a2[i]]=max(b1[j]-a1[i]+1,ys[b2[j]-a2[i]]);
			}
		}
	}
	for(i=1e6;i>=0;i--) xs[i]=max(xs[i],xs[i+1]),ys[i]=max(ys[i+1],ys[i]);
	for(i=1e6;i>=0;i--) ans=min(min(i+xs[i],i+ys[i]),ans);
	printf("%d\n",ans);
}