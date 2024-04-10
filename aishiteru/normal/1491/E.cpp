#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,f[N],vis[N],siz[N],u,v;
struct str{
	int u,v;
};
vector<str> e,e0,e1;
vector<int> g[N],eg;
void Gs(int n,int i,int fa)
{
	siz[i]=1;
	for(auto it:g[i])
		if(it!=fa)
		{
			Gs(n,it,i);
			siz[i]+=siz[it];
		}
	if(vis[siz[i]]&&vis[n-siz[i]])
		eg.push_back(i);
}
void Get(int i,int fa,int v,int fl)
{
	if(i==v)
		fl=1;
	for(auto it:g[i])
		if(it!=fa)
		{
			if(it!=v)
			if(fl==0)
				e0.push_back({i,it});
			else
				e1.push_back({i,it});
			Get(it,i,v,fl);
		}
}
bool dfs(vector<str> e)
{
	if(e.empty())
		return true;
	if(!vis[e.size()+1])
		return false;
	int i;
	for(auto it:e)
	{
		//cout<<it.u<<' '<<it.v<<endl;
		g[it.u].clear();
		g[it.v].clear();
	}
	for(auto it:e)
	{
		//cout<<it.u<<' '<<it.v<<endl;
		g[it.u].push_back(it.v);
		g[it.v].push_back(it.u);
	}
	eg.clear();
	Gs(e.size()+1,e[0].u,0);
	vector<int> p=eg;
	//cout<<p.size()<<endl;
	bool flag=false;
	for(auto it:p)
	{
		if(flag)
		{
		for(auto c:e)
		{
			g[c.u].clear();
			g[c.v].clear();
		}
		for(auto c:e)
		{
			g[c.u].push_back(c.v);
			g[c.v].push_back(c.u);
		}
	}
		e0.clear();
		e1.clear();
		Get(e[0].u,0,it,0);
		vector<str> ee[2];
		ee[0]=e0,ee[1]=e1;
		if(dfs(ee[0])&&dfs(ee[1]))
			return true;
		flag=true;
		break;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(i=2;i<=35;++i)
		f[i]=f[i-1]+f[i-2];
	for(i=0;i<=35;++i)
		if(f[i]<=n)
			vis[f[i]]=1;
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		e.push_back((str){u,v});
	}
	puts(dfs(e)?"YES":"NO");
}