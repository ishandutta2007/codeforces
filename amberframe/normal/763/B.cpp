#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("country.in","r",stdin);
		freopen("country.out","w",stdout);
	#endif
	int n;scanf("%d",&n);puts("YES");
	for (int l,r,u,d,i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&l,&r,&u,&d);
		swap(r,u);
		l<0?l=-l:0;u<0?u=-u:0;
		printf("%d\n",1+((l&1)|((u&1)<<1)));
	}
	return 0;
}