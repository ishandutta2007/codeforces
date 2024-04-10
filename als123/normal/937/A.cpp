#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int tt[605];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		tt[x]++;
	}
	int ans=0;
	for (int u=1;u<=600;u++)	ans=ans+(tt[u]>0);
	printf("%d\n",ans);
	return 0;
}