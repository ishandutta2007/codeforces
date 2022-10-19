#include<cstdio>
using namespace std;
int n,m,k,x,y,z,pr[10039],f[10039],ph,t,a[1039],tot;
int main(){
	register int i,j;
	for(i=2;i<=10000;i++){
		if(!f[i]) pr[++ph]=i;
		for(j=1;i*pr[j]<=1000&&j<=ph;j++){
			f[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
	f[0]=f[1]=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=ph;i++){
			if(pr[i]>=n&&f[pr[i]-n+1]){tot=pr[i]-n+1;break;}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++) printf("1 ");
			printf("%d ",tot);
			for(j=i+1;j<=n;j++) printf("1 ");
			printf("\n");
		}
	}
}