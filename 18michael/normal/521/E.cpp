#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=1;
int la[200002],dep[200002],fa[200002],fae[200002];
vector<int> vec,vece;
struct aaa
{
	int to,nx,num;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int d)
{
	dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!dep[v=edge[i].to])edge[fae[v]=i].num=edge[i^1].num=-1,fa[v]=x,dfs(v,d+1);
		if(x<v)vece.push_back(i);
	}
}
inline int LCA(int x,int y,int z)
{
	while(x!=y)
	{
		if(dep[x]<dep[y])swap(x,y);
		edge[fae[x]].num=edge[fae[x]].num=z,x=fa[x];
	}
	return x;
}
inline void Print(int x)
{
	printf("%d ",vec.size());
	if(vec[0]==x)for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
	else for(int i=vec.size()-1;~i;--i)printf("%d%c",vec[i],i? ' ':'\n');
	vec.clear();
}
inline void print(int x,int y,int t)
{
	puts("YES");
	int lx=LCA(edge[x].to,edge[x^1].to,-2),ly=LCA(edge[y].to,edge[y^1].to,-3),s=dep[lx]>dep[ly]? lx:ly,i;
	for(i=t;i!=s;i=fa[i])vec.push_back(i),edge[fae[i]].num=edge[fae[i]^1].num=0;
	vec.push_back(s),Print(s);
	for(i=s;i!=lx;i=fa[i])vec.push_back(i);
	vec.push_back(lx);
	for(i=lx;i!=edge[x].to && i!=edge[x^1].to;)
		for(int j=la[i],v;j;j=edge[j].nx)
			if(dep[v=edge[j].to]>dep[i] && edge[j].num==-2)
			{
				vec.push_back(i=v),edge[j].num=edge[j^1].num=0;
				break;
			}
	if(i==edge[x].to)i=edge[x^1].to;else i=edge[x].to;
	for(;i!=t;i=fa[i])vec.push_back(i),edge[fae[i]].num=edge[fae[i]^1].num=0;
	vec.push_back(t),Print(s);
	for(i=s;i!=ly;i=fa[i])vec.push_back(i);
	vec.push_back(ly);
	for(i=ly;i!=edge[y].to && i!=edge[y^1].to;)
		for(int j=la[i],v;j;j=edge[j].nx)
			if(dep[v=edge[j].to]>dep[i] && edge[j].num==-3)
			{
				vec.push_back(i=v),edge[j].num=edge[j^1].num=0;
				break;
			}
	if(i==edge[y].to)i=edge[y^1].to;else i=edge[y].to;
	for(;i!=t;i=fa[i])vec.push_back(i),edge[fae[i]].num=edge[fae[i]^1].num=0;
	vec.push_back(t),Print(s);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int j=1;j<=n;++j)
		if(!dep[j])
		{
			vece.clear(),dfs(j,1);
			for(int i=0,x,y;i<vece.size();++i)
				if(!edge[vece[i]].num)
				{
					x=edge[vece[i]].to,y=edge[vece[i]^1].to;
					while(x!=y)
					{
						if(dep[x]<dep[y])swap(x,y);
						if(~edge[fae[x]].num)return print(vece[i],edge[fae[x]].num,x),0;
						edge[fae[x]].num=edge[fae[x]^1].num=vece[i],x=fa[x];
					}
				}
		}
	return 0&puts("NO");
}