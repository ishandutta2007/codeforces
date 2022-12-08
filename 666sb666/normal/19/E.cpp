#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const int maxn=1e6+10;
int n,m,x[maxn],y[maxn],c[maxn],head[maxn],tot,color[maxn],d[maxn],depth[maxn],ff[maxn],root[maxn],eee,is[maxn]; 
bool vis[maxn];
struct E
{
	int to,next,id;
}edge[maxn<<1];
struct T
{
	int to,next;
}t[maxn<<1];
int hd[maxn],tt;
inline void add(int x,int y)
{
	t[++tt]=(T){y,hd[x]};
	hd[x]=tt;
	t[++tt]=(T){x,hd[y]};
	hd[y]=tt;
}
void dfs(int u,int fa,int d)
{
	vis[u]=1,depth[u]=d;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=fa&&vis[edge[i].to]==0)c[edge[i].id]=1,add(u,edge[i].to),dfs(edge[i].to,u,d+1);
}
void DFS(int u,int fa,int cr)
{
	color[u]=cr,ff[u]=fa;
	for(int i=hd[u];i!=-1;i=t[i].next)if(t[i].to!=fa)DFS(t[i].to,u,cr^1);
}
int work(int u,int fa)
{
	for(int i=hd[u];i!=-1;i=t[i].next)if(t[i].to!=fa)d[u]+=work(t[i].to,u);
	return d[u];
}
int main()
{
	memset(head,-1,sizeof(head));
	memset(hd,-1,sizeof(hd));
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		read(x[i]),read(y[i]);
		edge[++tot]=(E){y[i],head[x[i]],i};
		head[x[i]]=tot;
		edge[++tot]=(E){x[i],head[y[i]],i};
		head[y[i]]=tot;
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0,1),root[i]=1;
	for(int i=1;i<=n;i++)if(root[i])DFS(i,0,0);
	int total=0,ans=0;
	for(int i=1;i<=m;i++)
	if(!c[i]&&color[x[i]]==color[y[i]])
	{
		total++;
		if(depth[x[i]]<depth[y[i]])d[x[i]]--,d[y[i]]++;
		else d[x[i]]++,d[y[i]]--;
		eee=i;
	}
	else if(!c[i]&&color[x[i]]!=color[y[i]])
	{
		if(depth[x[i]]<depth[y[i]])d[x[i]]++,d[y[i]]--;
		else d[x[i]]--,d[y[i]]++;
	}
	if(!total)
	{
		write(m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		return 0;
	}
	if(total==1)is[eee]=1,ans=1;
	for(int i=1;i<=n;i++)if(root[i])work(i,0);
	for(int i=1;i<=n;i++)if(d[i]==total)ans++;
	write(ans);
	for(int i=1;i<=m;i++)if(c[i])
	if(ff[x[i]]==y[i]&&d[x[i]]==total)is[i]=1;
	else if(ff[y[i]]==x[i]&&d[y[i]]==total)is[i]=1;
	for(int i=1;i<=m;i++)if(is[i])printf("%d ",i);
	return 0;
}