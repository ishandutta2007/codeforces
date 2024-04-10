#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int la[N],pr[N*2],to[N*2],n,m,q,x,y,low[N],dfn[N],v[N],fa[N],cnt,ti;
set<int> s[N],t[N];
set<int>::iterator it;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void gg()
{
	puts("NO");
	exit(0);
}
inline void add(int x,int y)
{
	to[++cnt]=y;
	pr[cnt]=la[x];
	la[x]=cnt;
}
inline int merge(int a,int b)
{
	if (a==b)
		return a;
	if (t[a].size()+s[a].size()>t[b].size()+s[b].size())
		swap(a,b);	
	for (it=s[a].begin();it!=s[a].end();++it)
	{
		int k=*it;
		if (t[b].find(k)!=t[b].end())
			t[b].erase(k);
		else
			s[b].insert(k);
	}
	for (it=t[a].begin();it!=t[a].end();++it)
	{
		int k=*it;
		if (s[b].find(k)!=s[b].end())
			s[b].erase(k);
		else
			t[b].insert(k);
	}
	s[a].clear();
	t[a].clear();
	return b;
}
void tarjan(int x,int y)
{
	v[x]=1;
	low[x]=dfn[x]=++ti;
	int z=0;
	for (int i=la[x];i;i=pr[i])
		if (to[i]!=y)
		{
			if (!v[to[i]])
				tarjan(to[i],x);
			low[x]=min(low[x],low[to[i]]);
			fa[x]=merge(fa[x],fa[to[i]]);
		}
		else
		{
			++z;
			if (z==2)
			{
				if (!v[to[i]])
				tarjan(to[i],x);
				low[x]=min(low[x],low[to[i]]);
				fa[x]=merge(fa[x],fa[to[i]]);
			}
		}
	if (low[x]==dfn[x]&&s[fa[x]].size()&&t[fa[x]].size())
		gg();
}
int main()
{
	read(n);
	read(m);
	read(q);
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=q;++i)
	{
		read(x);
		read(y);
		s[x].insert(i);
		t[y].insert(i);
	}
	for (int i=1;i<=n;++i)
		fa[i]=i;
	for (int i=1;i<=n;++i)
	{
		if (!v[i])
			tarjan(i,0);
		if (s[fa[i]].size()||t[fa[i]].size())
			gg();
	}
	puts("YES");
	return 0;
}