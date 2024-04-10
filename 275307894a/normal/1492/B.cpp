#include<cstdio>
using namespace std;
int n,m,k,x,y,z,flag[100039],t,a[100039],head,now;
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);head=n;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),flag[a[i]]=i;
		for(i=n;i;i--){
			if(!flag[i]) continue;now=flag[i];
			for(j=flag[i];j<=head;j++) printf("%d ",a[j]),flag[a[j]]=0;head=now-1;
		}
		printf("\n");
	}
}