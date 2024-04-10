#include<cstdio>
using namespace std;
int n,m,k,x,y,z,fa[100039],w[100039],now1,now2,now3,now4,a[100039],now;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;(1<<i)<=n;i++){
		for(j=1;j<=n;j+=(1<<i)) fa[j+(1<<i-1)]=j;
	}
	for(i=2;i<=n;i++) printf("XOR %d %d\n",fa[i],i),fflush(stdout),scanf("%d",&w[i]);
	printf("AND 1 2\n");
	fflush(stdout);
	scanf("%d",&now1);
	now1=w[2]+2*now1;
	printf("AND 1 3\n");
	fflush(stdout);
	scanf("%d",&now2);
	now2=w[3]+2*now2;
	printf("AND 2 3\n");
	fflush(stdout);
	scanf("%d",&now3);
	now3=(w[2]^w[3])+2*now3;
	now4=(now1+now2+now3)/2;
	a[1]=now4-now3;a[2]=now4-now2;a[3]=now4-now1;
	for(i=2;i<=n;i++){
		now=i;a[i]=a[1];
		while(now!=1){
			a[i]^=w[now];now=fa[now];
		}
	}
	printf("! ");
	for(i=1;i<=n;i++) printf("%d ",a[i]);
}