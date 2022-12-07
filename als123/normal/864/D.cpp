#include<cstdio>
#include<cstring>
const int N=200005;
int n;
int a[N];
int tt[N];//
bool vis[N];// 
int main()
{
	memset(vis,false,sizeof(vis));
	int ans=0;
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		tt[a[u]]++;
	}
	int L=1;// 
	for (int u=1;u<=n;u++)
	{
		if (tt[u]==0)//
		{
			while (L<=n)
			{
				if (vis[a[L]]==true) vis[a[L]]=false;// 
				else if (tt[a[L]]>1) break;
				L++;
			}
			ans++;
			tt[a[L]]--;
			a[L]=u;
		}
		vis[u]=true;
	}
	printf("%d\n",ans);
	for (int u=1;u<=n;u++) printf("%d ",a[u]);
	return 0;
}