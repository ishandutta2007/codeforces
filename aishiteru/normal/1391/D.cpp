#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int f[4][N],a[4][N],o1,o2,n,m;
int main(){ 
	scanf("%d%d",&n,&m);it i;
	if(n>3) return puts("-1"),0;
	if(n==1) return putchar('0'),0;
	for(i=1;i<=n;++i)
		for(it j=1;j<=m;++j)
			scanf("%1d",&a[i][j]);
	if(n==2){
		for(i=1;i<=m;++i)
			i&1?(a[1][i]+a[2][i]&1?++o1:++o2):(a[1][i]+a[2][i]&1?++o2:++o1);
		return printf("%d\n",o1<o2?o1:o2),0;
	}
	o2=m;
	for(it j=0,x;j<4;++j){
		o1=0;
		for(i=1;i<=m;++i)
			x=((a[1][i]+a[2][i]&1)<<1)|(a[2][i]+a[3][i]&1),i&1?o1+=(x!=j):o1+=(x!=(3-j));
		o2=(o1<o2?o1:o2);
	}
	printf("%d",o2);
	return 0;
}