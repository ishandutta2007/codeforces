#include <bits/stdc++.h>

using namespace std;

int n;
long long t[100001];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%lld", &t[i]);
	}
	if(n==1)
	{
		printf("1 1\n%lld\n", -t[1]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
	printf("1 1\n");
	if(t[1]>0)
	{
		printf("%lld\n", -(t[1]%n));
		t[1]-=t[1]%n;
	}
	else
	{
		printf("%lld\n", abs(t[1])%n);
		t[1]+=abs(t[1])%n;
	}
	printf("2 %d\n", n);
	for(int i=2; i<=n; ++i)
	{
		if(t[i]>0)
		{
			printf("%lld ", (t[i]%n)*(n-1));
			t[i]+=(t[i]%n)*(n-1);
		}
		else
		{
			printf("%lld ", -((abs(t[i])%n)*(n-1)));
			t[i]-=(abs(t[i])%n)*(n-1);
		}
	}
	printf("\n1 %d\n", n);
	for(int i=1; i<=n; ++i)
	{
		printf("%lld ", -t[i]);
	}
	printf("\n");
	return 0;
}