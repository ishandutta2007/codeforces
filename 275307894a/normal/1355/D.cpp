#include<cstdio>
using namespace std;
int n,m,k,now,ans,tot,pus;
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	if(m<2*n) printf("NO");
	else{
		printf("YES\n");
		for(i=1;i<=n-1;i++) printf("2 ");
		printf("%d\n",m-(2*n-2));
		printf("1"); 
	}
	/*if(n%2==0){
		now=m-n+1;
		if(now>n/2+1){
			printf("YES\n");
			for(i=1;i<n/2;i++) printf("1 ");
			printf("%d ",now);
			for(i=1;i<=n/2;i++) printf("1 ");
			printf("\n%d",n/2+1);
		}
		else{
			printf("NO\n");
		}
	}
	else{
		now=m-n+1;
		if(now>n/2+1){
			printf("YES\n");
			for(i=1;i<=n/2;i++) printf("1 ");
			printf("%d ",now);
			for(i=1;i<=n/2;i++) printf("1 ");
			printf("\n%d",n/2+1);
		}
		else{
			printf("NO\n");
		}
	}*/
}