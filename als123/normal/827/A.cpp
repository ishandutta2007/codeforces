#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=6000005;
int n;
vector<int> vec[N];
int ans[N];
char ss[N];
int pos[N];
int main()
{
	memset(ans,-1,sizeof(ans));
	scanf("%d",&n);int mx=0;
	for (int u=1;u<=n;u++)
	{
		scanf("%s",ss+1);int m=strlen(ss+1);
		for (int i=1;i<=m;i++) vec[u].push_back(ss[i]-'a');
		int k;scanf("%d",&k);
		while (k--)
		{
			int x;scanf("%d",&x);
			if (pos[x]==0) pos[x]=u;
			else if (vec[pos[x]].size()<vec[u].size()) pos[x]=u;
			mx=max(mx,x+m-1);
		}
	}
	for (int u=1;u<=mx;u++)
	{
		if (pos[u]!=-1)
		{
			int x=pos[u],siz=vec[x].size(),now=u;
			for (int i=0;i<siz;i++)
			{
				ans[now]=vec[x][i];
				now++;
			//	printf("%d %d %d %d %d\n",u,now,x,pos[now],vec[x].size()-i-1);
				if (pos[now]!=0&&vec[pos[now]].size()>=vec[x].size()-i-1) break;
				else pos[now]=0;
			}
		}
		if (ans[u]==-1) printf("a");
		else printf("%c",ans[u]+'a');
	}
	return 0;
}