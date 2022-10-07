#include <cstdio>
int n,sum;
int main(){
	scanf("%d",&n);
	for (register int i=1,x;i<=n;++i) scanf("%d",&x),sum+=x;
	for (register int i=1,x;i<=n;++i) scanf("%d",&x),sum-=x;
	if (sum<0) printf("No"); else printf("Yes");
}