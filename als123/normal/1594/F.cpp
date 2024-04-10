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
		LL s,n,k;
		scanf("%lld%lld%lld",&s,&n,&k);
		if (s<k)  printf("NO\n");
		else if (s==k) printf("YES\n");
		else
		{
			LL x=k*(s/k/2);
			x=x+min(k,s%(k*2));
			x=x-(s/k)%2;
			if (x>=n) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}