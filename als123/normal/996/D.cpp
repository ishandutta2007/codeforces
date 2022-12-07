#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=205;
int n;
int a[N];
bool vis[N];
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);n<<=1;
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		if (vis[u]==true) continue;
		int t=a[u];
		for (int i=u+1;i<=n;i++)
		{
			if (vis[i]) continue;
			if (a[i]==t) 
			{
				//printf("%d %d\n",u,i);
				vis[i]=true;
				break;
			}
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}