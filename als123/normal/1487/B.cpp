#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if (n%2==0)
		{
			if (k%n==0) printf("%d\n",n);
			else printf("%d\n",k%n);
		}
		else
		{
			int t=n/2;
			k=k+(k-1)/t;
			if (k%n==0) printf("%d\n",n);
			else printf("%d\n",k%n);
		}
	}
	return 0;
}