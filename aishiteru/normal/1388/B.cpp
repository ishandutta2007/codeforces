#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n;
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);it k=(n-1)/4+1,b=n-k;
		while(b--) putchar('9');
		while(k--) putchar('8');
		puts("");
	}
	return 0;
}