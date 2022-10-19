#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,t,f[339][339],a[339];
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		if(m%n==0) printf("0\n");
		else printf("2\n");
		if(m<=n){
			for(i=1;i<=m;i++) f[i][i]=1;
		}
		else{
			for(i=1;i<=n;i++) f[i][i]=1;
			for(i=1;i<=n;i++) a[i]=i;
			for(i=1;i<=(m-n)/n;i++){
				for(j=1;j<=n;j++) a[j]=a[j]%n+1,f[j][a[j]]=1;
			}
			for(j=1;j<=m%n;j++) a[j]=a[j]%n+1,f[j][a[j]]=1;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) printf("%d",f[i][j]);
			printf("\n");
		}
	}
}