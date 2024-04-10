#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,a[N],cn[N];
int main(){
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d",&n);it maxn=0,num=0;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),cn[i]=0;
		for(i=1;i<=n;++i) ++cn[a[i]],maxn=(cn[a[i]]>maxn?cn[a[i]]:maxn);
		for(i=1;i<=n;++i) num+=(cn[i]==maxn);
		printf("%d\n",maxn==1?n:(n-num)/(maxn-1)-1);
	} 
	return 0;
}