#include <stdio.h>

typedef long long lli;

int main() {
	int i;
	lli n;
	scanf("%lld",&n);
	for(i=2;i<n && i<=10000000;i++) {
		if(n%i==0){
			int j;
			for(int j=2;j<=n/i && j<=10000000;j++) {
				if((n/i)%j==0 && n/i/j!=1){
					printf("1\n%lld",1ll*i*j);
					return 0;
				}
			}
			printf("2");
			return 0;
		}
	}
	printf("1\n0");

	return 0;
}