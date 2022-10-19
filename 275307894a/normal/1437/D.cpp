#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,a[200039],head,ans,tot,pus,st[200039];
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		while(head--) st[head]=0;
		head=1;
		st[head++]=1;st[head]=1;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==1){printf("1\n");break;}
		for(i=3;i<=n;i++){
			if(a[i]<a[i-1]){
				st[head-1]--;
				if(!st[head-1]) st[++head]=1;
				else st[head]++;
			}
			else st[head]++;
		} 
		printf("%d\n",head-1);
	}
}