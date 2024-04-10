#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,sum;
int deg[2002],id[2002];
char s[2002][2002];
typedef pair<int,int> P;
P ans=P(inf,0);
inline bool cmp(int x,int y)
{
	return deg[x]<deg[y];
}
inline bool check()
{
	sort(id+1,id+n+1,cmp),sum=0;
	for(int i=1;i<n;++i)if(!(sum+=deg[id[i]]-i+1))return 1;
	return 0;
}
inline void upd(P p)
{
	if(p.first<ans.first)ans=p;
	else if(p.first==ans.first)ans.second+=p.second;
}
inline void dfs(int x,int y)
{
	if(x>n)
	{
		if(!check())upd(P(y,1));
		return ;
	}
	dfs(x+1,y);
	for(int i=1;i<=n;s[x][i]^=1,s[i][x]^=1,++i)
	{
		if(s[x][i]=='0')--deg[i],++deg[x];
		else --deg[x],++deg[i];
	}
	dfs(x+1,y+1);
	for(int i=1;i<=n;s[x][i]^=1,s[i][x]^=1,++i)
	{
		if(s[x][i]=='0')--deg[i],++deg[x];
		else --deg[x],++deg[i];
	}
}
inline void solve1()
{
	dfs(1,0);
	if(ans.first<inf)for(int i=1;i<=ans.first;++i)ans.second*=i;
}
inline void solve2()
{
	if(!check())return (void)(ans=P(0,1));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(s[i][j]=='0')--deg[j],++deg[i];
			else --deg[i],++deg[j];
		}
		if(!check())upd(P(1,1));
		for(int j=1;j<=n;++j)
		{
			if(s[i][j]=='0')++deg[j],--deg[i];
			else ++deg[i],--deg[j];
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1),id[i]=i;
		for(int j=1;j<=n;++j)if(s[i][j]=='1')++deg[i];
	}
	if(n<=6)solve1();
	else solve2();
	if(ans.first==inf)puts("-1");
	else printf("%d %d",ans.first,ans.second);
	return 0;
}