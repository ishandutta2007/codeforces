#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&x,&y);
		if (x==0&&y==0)
		{
			puts("0");
			continue;
		}
		if (x%2!=y%2)
		{
			puts("-1");
			continue;
		}
		if (x==y)
		{
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}