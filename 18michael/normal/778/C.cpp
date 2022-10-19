#include<bits/stdc++.h>
using namespace std;
int n,mx=1,ans,num,res,edge_t=0;
char ch;
int la[300008]={};
bool u[300008]={};
vector<int> vec;
vector<int> v[300008];
struct aaa
{
	int siz,son;
	int to[26];
}tree[300008],tree1[300008];
struct bbb
{
	int to,nx;
	char ch;
}edge[600008];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,char ch)
{
	edge[++edge_t]=(bbb){y,la[x],ch},la[x]=edge_t;
	edge[++edge_t]=(bbb){x,la[y],ch},la[y]=edge_t;
}
inline void dfs(int x,int y,int d)
{
	tree[x].siz=1,tree[x].son=0,v[d].push_back(x),mx=max(mx,d);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=y)
		{
			tree[x].to[edge[i].ch-'a']=v,dfs(v,x,d+1),tree[x].siz+=tree[v].siz;
			if(!tree[x].son || tree[v].siz>tree[tree[x].son].siz)tree[x].son=v;
		}
	tree1[x]=tree[x];
}
inline int merge(int x,int y)
{
	if(!x || !y)return (x|y);++res;
	if(!u[x])vec.push_back(x),u[x]=1;
	if(!u[y])vec.push_back(y),u[y]=1;
	for(int i=0;i<26;++i)tree[x].to[i]=merge(tree[x].to[i],tree[y].to[i]);
	return x;
}
inline void solve(int x)
{
	int rt=tree[x].son;if(!rt)return ;
	if(!u[x])vec.push_back(x),++res,u[x]=1;
	for(int i=0,v;i<26;++i)
		if((v=tree[x].to[i]) && v!=tree[x].son)
			rt=merge(v,rt);
}
int main()
{
	read(n),ans=n,add_edge(0,1,'a');
	for(int i=1,x,y,z;i<n;++i)
	{
		scanf("%d%d",&x,&y);do ch=getchar();while(ch<'a' || ch>'z');
		add_edge(x,y,ch);
	}
	dfs(0,0,0);
	for(int i=2;i<=mx;++i)
	{
		res=0;
		for(int j=0;j<v[i-1].size();++j)solve(v[i-1][j]);
		if(n-res<ans)ans=n-res,num=i-1;
		for(int j=0;j<vec.size();++j)tree[vec[j]]=tree1[vec[j]],u[vec[j]]=0;
		vec.clear();
	}
	printf("%d\n%d",ans,num);
	return 0;
}