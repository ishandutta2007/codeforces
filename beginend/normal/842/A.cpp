#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int l,r,x,y,k;
	scanf("%d%d%d%d%d",&l,&r,&x,&y,&k);
	for (int i=l;i<=r;i++)
	{
		if (i%k!=0) continue;
		int w=i/k;
		if (w>=x&&w<=y)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}