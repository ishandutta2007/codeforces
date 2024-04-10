#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 100005;
const int N = 100001;

int prm[maxn],is[maxn],tot,n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("girlfriend.in","r",stdin);
		freopen("girlfriend.out","w",stdout);
	#endif
	for (int i=2;i<=N;i++)
	{
		if (!is[i]) prm[++tot]=i;
		for (int j=1;j<=tot;j++)
		{
			int num=prm[j]*i;
			if (num>N) break;
			is[num]=1;
			if (i%prm[j]==0) break;
		}
	}
	scanf("%d",&n);
	if (n==1) printf("1\n1");
	if (n==2) printf("1\n1 1");
	if (n>2) {
		printf("2\n");
		for (int i=2;i<=n+1;i++)
			printf("%d ",is[i]+1);
	}
	return 0;
}