#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
int ans,n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("aimr.in","r",stdin);
		freopen("aimr.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1,j=n;i<j;i++,j--)
	{
		ans+=(i+j)%(n+1);
		if (i+1!=j) ans+=(i+1+j)%(n+1);
	}
	printf("%d",ans);
	return 0;
}