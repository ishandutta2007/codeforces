#include<bits/stdc++.h>

bool vis[10];

bool check(int x)
{
	memset(vis,0,sizeof(vis));
	while (x)
	{
		if (vis[x%10]) return 0;
		vis[x%10]=1;
		x/=10;
	}
	return 1;
}

int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	for (int i=l;i<=r;i++) if (check(i)) {printf("%d\n",i);return 0;}
	puts("-1");
	return 0;
}