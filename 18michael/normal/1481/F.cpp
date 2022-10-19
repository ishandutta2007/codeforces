#include<bits/stdc++.h>
using namespace std;
int n,X,edge_t=0,dp_t=0,mx=0;
int la[100002],pre[100002],siz[100002];
bool u[100002];
vector<int> vec[100002],vec2[100002];
bitset<100002> dp[452];
char s[100002];
struct aaa
{
	int to,nx;
}edge[100002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,u[x]=1;
}
inline void dfs(int x,int d)
{
	vec[d].push_back(x),mx=max(mx,d);
	for(int i=la[x];i;i=edge[i].nx)dfs(edge[i].to,d+1);
}
int main()
{
	scanf("%d%d",&n,&X),dp[0].set(0);
	for(int i=1;i<=n;++i)s[i]='b';
	for(int i=2,x;i<=n;++i)scanf("%d",&x),add_edge(x,i);
	dfs(1,1);
	for(int i=1;i<=mx;++i)vec2[vec[i].size()].push_back(i);
	for(int i=1;i<=n;++i)
		if(vec2[i].size())
		{
			for(int j=0;j<=n;++j)pre[j]=(j>=i? pre[j-i]:0)+dp[dp_t].test(j)-(j-((int)vec2[i].size()+1)*i>=0? dp[dp_t].test(j-(vec2[i].size()+1)*i):0);
			siz[++dp_t]=i;
			for(int j=0;j<=n;++j)if(pre[j]>0)dp[dp_t].set(j);
		}
	if(dp[dp_t].test(X))
	{
		printf("%d\n",mx);
		for(int i=dp_t;i;--i)
			for(int j=0;j<=vec2[siz[i]].size();++j)
				if(dp[i-1].test(X-j*siz[i]))
				{
					for(int k=0;k<j;++k)for(int l=0;l<siz[i];++l)s[vec[vec2[siz[i]][k]][l]]='a';
					X-=j*siz[i];
					break;
				}
	}
	else
	{
		printf("%d\n",mx+1);
		for(int i=1,x;i<=mx;++i)
		{
			for(int j=x=0;j<vec[i].size();++j)x+=u[vec[i][j]];
			if(x<=X)
			{
				for(int j=0;j<vec[i].size();++j)if(u[vec[i][j]])s[vec[i][j]]='a';
				X-=x;
				if(vec[i].size()-x<=X)
				{
					for(int j=0;j<vec[i].size();++j)if(!u[vec[i][j]])s[vec[i][j]]='a';
					X-=vec[i].size()-x;
				}
				else
				{
					for(int j=0;j<vec[i].size();++j)if(!u[vec[i][j]] && X)s[vec[i][j]]='a',--X;
					break;
				}
			}
			n-=x;
			if(vec[i].size()-x<=n-X)n-=vec[i].size()-x;
			else
			{
				for(int j=0;j<vec[i].size();++j)
					if(!u[vec[i][j]])
					{
						if(n^X)--n;
						else s[vec[i][j]]='a';
					}
				for(int j=i+1;j<=mx;++j)for(int k=0;k<vec[j].size();++k)s[vec[j][k]]='a';
				break;
			}
		}
	}
	return 0&printf("%s",s+1);
}