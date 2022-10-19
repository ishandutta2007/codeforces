#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[200039],flag[200039],ans,tot,pus;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++) scanf("%d",a+i),flag[i]=(a[i]==i)?1:0;
		ans=tot=pus=0;
		for(i=1;i<=n;i++){
			if(flag[i]){
				if(tot) pus++;
				tot=0;
			}
			else tot++;
		}
		if(tot) pus++;
		if(pus>=2) printf("2\n");
		else printf("%d\n",pus);
	}
}