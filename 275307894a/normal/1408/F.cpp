#include<cstdio>
using namespace std;
int n,m,k,z,a[100039],s,head,x[1000039],y[1000039];
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=0;i<=30;i++) if(n<=(1<<i)) {k=i;break;}
	k--;
	for(i=1;i<=k;i++){
		for(j=1;j<=(1<<k);j++) if(!((j-1)&(1<<i-1))) x[++head]=j,y[head]=j+(1<<i-1);
	}
	for(i=1;i<=k;i++){
		for(j=1;j<=(1<<k);j++) if(!((j-1)&(1<<i-1))) x[++head]=n-j+1,y[head]=n-j+1-(1<<i-1);
	}
	printf("%d\n",head);
	for(i=1;i<=head;i++) printf("%d %d\n",x[i],y[i]);
}