#include<cstdio>
#define max(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,x,y,z,a[13][13],flag,ans,tot,t;
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans=0;tot=1e9;flag=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) scanf("%d",&a[i][j]),flag^=(a[i][j]<0?1:0),ans+=abs(a[i][j]);
		}
		if(!flag) printf("%d\n",ans);
		else{
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++) tot=max(tot,abs(a[i][j]));
			}
			printf("%d\n",ans-2*tot);
		}
	}
}