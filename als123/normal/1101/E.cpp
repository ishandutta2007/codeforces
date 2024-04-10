#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int mx=0,mx1=0;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		char ss[5];
		scanf("%s",ss);
		if (ss[0]=='+')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x<y) swap(x,y);
			mx=max(mx,x);
			mx1=max(mx1,y);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x<y) swap(x,y);
			if (mx<=x&&mx1<=y) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}