#include<cstdio>
#include<cstring>
const int N=205;
int n;
char ss[N];
bool vis[N];
int ans=0;
int main()
{
	scanf("%d",&n);
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)
	{
		int tot=0;
		memset(vis,false,sizeof(vis));
		for (int i=u;i<=n;i++)
		{
			if (ss[i]>='A'&&ss[i]<='Z') break;
			int t=ss[i]-'a';
			if (vis[t]==false)
			{
				vis[t]=true;
				tot++;
			}
		}
		if (tot>ans) ans=tot;
	}
	printf("%d\n",ans);
	return 0;
}