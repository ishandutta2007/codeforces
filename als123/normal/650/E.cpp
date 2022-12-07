#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef pair<int,int> PI;
const int N=500005;
struct qq{int x,y,last;}e[N*2];int num,last[N];
int n;
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
set<PI> s[N];
set<PI>::iterator it;
int f[N];
int find (int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
void Merge (int x,int y)// 
{
	x=find(x);y=find(y);
	if (s[x].size()<s[y].size()) swap(x,y);
	f[y]=x;
	for (it=s[y].begin();it!=s[y].end();it++)	s[x].insert(*it);
	s[y].clear();
}
struct qt
{
	int x1,y1;
	int x2,y2;
}Ans[N];int tot=0;
void dfs (int x,int fa)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
	}
	if (fa==0) return ;
	int p=x,q=fa;
	if (p>q) swap(p,q);
	if (s[find(x)].count(make_pair(p,q))!=0)// 
	{
		s[find(x)].erase(make_pair(p,q));
		s[find(fa)].erase(make_pair(p,q));
		Merge(p,q);
	}
	else// 
	{
		p=find(x);
		PI xx=*s[p].begin();//
		q=find(xx.first)==p?find(xx.second):find(xx.first);
		Ans[++tot]=qt{x,fa,xx.first,xx.second};
		s[p].erase(xx);s[q].erase(xx);
		Merge(p,q);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	for (int u=1;u<=n;u++) f[u]=u;
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		s[x].insert(make_pair(x,y));
		s[y].insert(make_pair(x,y));
	}
	dfs(1,0);
	printf("%d\n",tot);
	for (int u=1;u<=tot;u++)	printf("%d %d %d %d\n",Ans[u].x1,Ans[u].y1,Ans[u].x2,Ans[u].y2);
	return 0;
}