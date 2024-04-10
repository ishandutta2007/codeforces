#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int a[20];// 
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++)
	{
		int x=0;
		for (int u=1;u<=k;u++)
		{
			int lalal;
			scanf("%d",&lalal);
			x=(x<<1)+lalal;
		}
		a[x]++;
	}
	bool tf=false;
	for (int u=0;u<=16;u++)
	{
		if (a[u]==0) continue;
		for (int i=0;i<=16;i++)
		{
			if (a[i]==0) continue;
			if ((u&i)==0) tf=true;
		}
	}
	if (tf) printf("YES\n");
	else printf("NO\n");
	return 0;
}