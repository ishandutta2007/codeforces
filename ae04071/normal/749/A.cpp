#include <stdio.h>
#include <vector>

int n;
bool prime[100001];

int main()
{
	for(int i=2;i<=100000;i++) {
		if(!prime[i]) {
			for(int j=i*i; j<=100000;j+=2) {
				prime[j] = true;
			}
		}
	}

	scanf("%d",&n);
	if(n%2) {
		int cnt = 1;
		n -=3;
		cnt += n/2;
		printf("%d\n", cnt);
		for(int i=0;i<n/2;i++) {
			printf("%d ", 2);
		}
		printf("%d",3);
	}
	else 
	{
		int cnt=n/2;
		printf("%d\n", cnt);
		for(int i=0;i<n/2;i++) {
			printf("%d ",2);
		}
	}


	return 0;
}