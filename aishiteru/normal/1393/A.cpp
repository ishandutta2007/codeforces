#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,a[N],cn[N];
int main(){
	scanf("%d",&T);
	while(T--) scanf("%d",&n),printf("%d\n",n+2>>1);
	return 0;
}