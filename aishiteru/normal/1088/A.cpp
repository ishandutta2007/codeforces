#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
#define P 998244353
typedef long long ll;
#define rll register ll
#define cll const ll
int x;
int main(){ 
	scanf("%d",&x);
	if(x==1) return puts("-1"),0;
	printf("%d %d",x,x);
	return 0;
}