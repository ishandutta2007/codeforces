#include<bits/stdc++.h>
using namespace std;
int n,t;
int fa[5002],siz[5002];
bitset<5002> bs;
vector<int> vec[5002];
struct aaa
{
	int x,y;
	inline void get()
	{
		for(y=x;fa[y]^1;y=fa[y]);
	}
}a,b,c,d;
inline void dfs(int x)
{
	siz[x]=(!vec[x].size());
	for(int i=0,v;i<vec[x].size();++i)dfs(v=vec[x][i]),siz[x]+=siz[v];
}
inline bool check(aaa a,aaa b,aaa c,aaa d)
{
	if(siz[1]&1)return 0;
	bs.reset(),bs.set(siz[c.y]);
	for(int i=0,v;i<vec[1].size();++i)if((v=vec[1][i])!=a.y && v!=b.y)bs|=(bs<<siz[v]);
	for(int now=fa[t=a.x];now^1;now=fa[t=now])for(int i=0,v;i<vec[now].size();++i)if((v=vec[now][i])!=t)bs|=(bs<<siz[v]);
	for(int now=fa[t=b.x];now^1;now=fa[t=now])for(int i=0,v;i<vec[now].size();++i)if((v=vec[now][i])!=t)bs|=(bs<<siz[v]);
	return bs.test((siz[1]>>1)-1);
}
int main()
{
	scanf("%d%d%d%d%d",&n,&a.x,&b.x,&c.x,&d.x);
	for(int i=2;i<=n;++i)scanf("%d",&fa[i]),vec[fa[i]].push_back(i);
	a.get(),b.get(),c.get(),d.get(),dfs(1),puts((check(a,b,c,d) && check(c,d,a,b))? "YES":"NO");
	return 0;
}