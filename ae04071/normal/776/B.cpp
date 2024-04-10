#include <stdio.h>

bool prime[100001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=350;i++) {
		if(!prime[i]) {
			for(int j=i*i;j<=100001;j+=i)
				prime[j]=true;
		}
	}

	bool flag=false;
	for(int i=2;i<=n+1;i++) {
		if(prime[i]) {
			flag=true;
			break;
		}
	}
	if(flag) printf("2\n");
	else printf("1\n");
	for(int i=2;i<=n+1;i++) {
		if(prime[i]) printf("2 ");
		else printf("1 ");
	}

	return 0;
}