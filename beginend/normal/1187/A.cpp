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
		int n,s,t;scanf("%d%d%d",&n,&s,&t);
		printf("%d\n",std::max(s,t)-(s+t-n)+1);
	}
	return 0;
}