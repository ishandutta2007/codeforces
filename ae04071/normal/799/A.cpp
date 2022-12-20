#include <cstdio>
#include <algorithm>

int n,t,k,d;
int main() {
	scanf("%d %d %d %d",&n,&t,&k,&d);
	int a=(n/k+(n%k!=0))*t;
	int b=a-d;
	if(b>t) printf("YES\n");
	else printf("NO\n");
	return 0;
}