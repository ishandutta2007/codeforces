#include<bits/stdc++.h>
using namespace std;
char s[12][105],jl[105],fn[105];
int n,l[12],ans;
map<vector<int>,int>mp;
void dfs(int x,auto g)
{
	if(mp[g]>=x)return;
	mp[g]=x;
	if(ans<x)
	{
		ans=x;
		for(int i=1;i<=x;i++)fn[i]=jl[i];
	}
	for(char i='A';i<='Z';i++)
	{
		jl[x+1]=i;
		vector<int>h(n+1,-1);
		for(int j=1;j<=n;j++)
		{
			int ww=g[j];
			while(ww<=l[j]&&s[j][ww]!=i)ww++;
			if(ww>l[j])
			{
				jl[x+1]=-1;
				break;
			}
			h[j]=ww+1;
		}
		if(jl[x+1]!=-1)dfs(x+1,h);
	}
	for(char i='a';i<='z';i++)
	{
		jl[x+1]=i;
		vector<int>h(n+1,-1);
		for(int j=1;j<=n;j++)
		{
			int ww=g[j];
			while(ww<=l[j]&&s[j][ww]!=i)ww++;
			if(ww>l[j])
			{
				jl[x+1]=-1;
				break;
			}
			h[j]=ww+1;
		}
		if(jl[x+1]!=-1)dfs(x+1,h);
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			l[i]=strlen(s[i]+1);
		}
		ans=0;
		mp.clear();
		mp[vector<int>(n+1,1)]=-1;
		dfs(0,vector<int>(n+1,1));
		fn[ans+1]=0;
		printf("%d\n%s\n",ans,fn+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=l[i];j++)s[i][j]=0;
	}
	return 0;
}