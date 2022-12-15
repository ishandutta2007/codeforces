#include <cstdio>
#include <algorithm>

int main() {
	int n;
	scanf("%d",&n);
	if(n==1) {
		printf("0\n");
		return 0;
	}
	int res=n/2-1;
	if(n&1) {
		res++;
	}
	printf("%d\n",res);
	
	return 0;
}