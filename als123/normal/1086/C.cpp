#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
char a[N],b[N],c[N];
int n,k;
int ans[N],ans1[N];
bool vis[N];
bool vis1[N];
bool checka (int tx)
{
	for (int u=1;u<=k;u++) vis1[u]=vis[u],ans1[u]=ans[u];
	for (int u=tx;u<=n;u++)
	{
		int x=a[u]-'a'+1,xx=c[u]-'a'+1;
		if (ans1[xx]==-1)
		{
			for (int i=k;i>=1;i--)
			{
				if (vis1[i]==false)	{ans1[xx]=i;vis1[i]=true;break;}
			}
		}
		if (ans1[xx]>x) break;
		if (ans1[xx]<x) return false;
	}
	for (int u=1;u<=k;u++) if (ans1[u]==-1)
	for (int i=1;i<=k;i++) if (vis1[i]==false)
	{ans1[u]=i;vis1[i]=true;break;}
	for (int u=1;u<=k;u++) ans[u]=ans1[u];
	return true;
}
bool checkb (int tx)
{
	for (int u=1;u<=k;u++) vis1[u]=vis[u],ans1[u]=ans[u];
	//printf("%d %d\n",ans1[3],ans[3]);
	for (int u=tx;u<=n;u++)
	{
		int x=b[u]-'a'+1,xx=c[u]-'a'+1;
		if (ans1[xx]==-1)
		{
			//printf("FUCK:%d\n",u);
			for (int i=1;i<=k;i++)
			{
				if (vis1[i]==false)	{ans1[xx]=i;vis1[i]=true;break;}
			}
		}
		//printf("%d %d %d %d\n",u,x,xx,ans1[xx]);
		if (ans1[xx]<x) break;
		if (ans1[xx]>x) return false;
	}
	for (int u=1;u<=k;u++) if (ans1[u]==-1)
	for (int i=1;i<=k;i++) if (vis1[i]==false)
	{ans1[u]=i;vis1[i]=true;break;}
	for (int u=1;u<=k;u++) ans[u]=ans1[u];
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&k);
		for (int u=1;u<=k;u++) ans[u]=-1,vis[u]=false;;
		scanf("%s%s%s",c+1,a+1,b+1);
		n=strlen(a+1);
		bool tf=true;
		for (int u=1;u<=n;u++)
		{
			if (b[u]<a[u])	{tf=false;break;}
			else if (a[u]==b[u])
			{
				int x=c[u]-'a'+1,y=a[u]-'a'+1;
				if (ans[x]!=-1)
				{
					if (ans[x]==y) continue;
					else {tf=false;	break;}
				}
				else 	
				{
					if (vis[y]) {tf=false;break;}
					//printf("Ins:%d %d\n",x,y);
					ans[x]=y;vis[y]=true;
				}
			}
			else
			{
				int l=a[u]-'a'+1,r=b[u]-'a'+1;
				int x=c[u]-'a'+1;
				if (ans[x]!=-1)
				{
					if (ans[x]==r)
					{
						//printf("YES:%d %d %d\n",x,u,r);
						if (checkb(u)==false) tf=false;
					}
					if (ans[x]==l)
					{
						if (checka(u)==false) tf=false;
					}
					if (ans[x]>r||ans[x]<l)	tf=false;
					break;
				}
				bool ok=false;
				for (int i=l+1;i<r;i++)
				{
					if (vis[i]==false)
					{
						ok=true;
						vis[i]=true;
						ans[x]=i;break;
					}
				}
				if (ok) break;
				if (vis[l]==false)
				{
					vis[l]=true;ans[x]=l;
					if (checka(u)) break;
					vis[l]=false;ans[x]=-1;
				}
				if (vis[r]==false)
				{
					vis[r]=true;ans[x]=r;
					if (checkb(u)) break;
					vis[r]=false;ans[x]=-1;
				}
				tf=false;
				break;
			}
		}
		if (tf==false)	{printf("NO\n");continue;}
		for (int u=1;u<=k;u++) if (ans[u]==-1)
		for (int i=1;i<=k;i++) if (vis[i]==false)
		{ans[u]=i;vis[i]=true;break;}
		printf("YES\n");
		for (int u=1;u<=k;u++) printf("%c",ans[u]+'a'-1);
		printf("\n");
	}
	return 0;
}