#include <stdio.h>

int main()
{
	int k,a,b;
	scanf("%d %d %d",&k,&a,&b);
	if(a<k && b<k) {
		printf("-1\n");
		return 0;
	}
	if(a<k) {
		if(b%k!=0) {
			printf("-1\n");
			return 0;
		}
	}
	if(b<k) {
		if(a%k!=0) {
			printf("-1\n");
			return 0;
		}
	}

	int cnt=a/k+b/k;
	printf("%d\n",cnt);

	return 0;
}