#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,flag[233],vis[233];
char s1[520233],s2[520233];
vector<int> G[233],rec;
int ans,ra[233],rb[233];
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=true;
	rec.push_back(u);
	for(auto v:G[u])dfs(v);
}
int main()
{
	scanf("%d%s%s",&n,s1+1,s2+1);
	for(int i=1,u,v;i<=n;++i)
	{
		u=s1[i]-'a'+1;
		v=s2[i]-'a'+1;
		G[u].push_back(v);
		G[v].push_back(u);
		flag[u]=flag[v]=true;
	}
	for(int i=1;i<='z'-'a'+1;++i)
	{
		if(flag[i]&&!vis[i])
		{
			rec.clear();
			dfs(i);
			for(int i=1;i<rec.size();++i)
			{
				ra[++ans]=rec[i];
				rb[ans]=rec[0];
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
	{
		printf("%c %c\n",ra[i]+'a'-1,rb[i]+'a'-1);
	}
	return 0;
}