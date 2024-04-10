#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n,k;scanf("%d%d",&n,&k);
		if (k%3!=0||n<k)
		{
			if (n%3==0) puts("Bob");
			else puts("Alice");
		}
		else
		{
			if (n%(k+1)==0||n%(k+1)%3==0&&n%(k+1)!=k) puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}