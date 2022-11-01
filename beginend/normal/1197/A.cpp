#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		printf("%d\n",std::min(n-2,std::min(a[n],a[n-1])-1));
	}
	return 0;
}