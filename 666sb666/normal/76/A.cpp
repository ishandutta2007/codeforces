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
const int N=205,M=50005;
struct EDGE
{
	int x,y,z,w;
}e[M],tree[N];
inline bool cmp(EDGE a,EDGE b)
{
	return a.z<b.z;
}
inline bool CMP(EDGE a,EDGE b)
{
	return a.w<b.w;
}
struct E
{
	int to,next,x,y;
}edge[N<<1];
int n,m,G,S,g[M],s[M],head[N],tot,fa[N],dep[N],v[N],cnt=0;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,int f,int d,int val)
{
	fa[u]=f,dep[u]=d,v[u]=val;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=f)dfs(edge[i].to,u,d+1,edge[i].y);
}
inline int mxx(int a,int b)
{
	return a>b?a:b;
}
inline int baolilca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
int main()
{
	read(n),read(m),read(G),read(S);
	for(int i=1;i<=m;i++)read(e[i].x),read(e[i].y),read(g[i]),read(s[i]),e[i].z=g[i],e[i].w=s[i];
	sort(e+1,e+m+1,cmp);
	int num=n,now; 
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y)continue;
		num--,fa[x]=y;
		if(num==1)
		{
			now=i;
			break;
		}
	}
	if(num>1)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+now+1,CMP);
	for(int i=1;i<=now;i++)
	{
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y)continue;
		tree[++cnt]=(EDGE){e[i].x,e[i].y,e[i].z,e[i].w};
		fa[x]=y;
	}
	long long ans;
	int mxg=0,mxs=0;
	for(int i=1;i<n;i++)
	{
		if(tree[i].z>mxg)mxg=tree[i].z;
		if(tree[i].w>mxs)mxs=tree[i].w;
	}
	ans=(long long)mxg*G+(long long)mxs*S;
	for(int i=now+1;i<=m;i++)
	{
		if(e[i].x==e[i].y)continue;
		tot=0;
		memset(head,-1,sizeof(head));
		for(int j=1;j<n;j++)
		{
			edge[++tot]=(E){tree[j].y,head[tree[j].x],tree[j].z,tree[j].w};
			head[tree[j].x]=tot;
			edge[++tot]=(E){tree[j].x,head[tree[j].y],tree[j].z,tree[j].w};
			head[tree[j].y]=tot;
		}
		dfs(1,0,1,0);
		int x=e[i].x,y=e[i].y,z=baolilca(x,y),t,id;
		if(x!=z)t=x;
		else t=y;
		while(x!=z)
		{
			if(v[x]>v[t])t=x;
			x=fa[x];
		}
		while(y!=z)
		{
			if(v[y]>v[t])t=y;
			y=fa[y];
		}
		for(int j=1;j<n;j++)if((tree[j].x==t&&tree[j].y==fa[t])||(tree[j].x==fa[t]&&tree[j].y==t))id=j;
		if(e[i].w<tree[id].w)tree[id]=(EDGE){e[i].x,e[i].y,e[i].z,e[i].w};
		long long tmp;
		int mxg=0,mxs=0;
		for(int j=1;j<n;j++)
		{
			if(tree[j].z>mxg)mxg=tree[j].z;
			if(tree[j].w>mxs)mxs=tree[j].w;
		}
		tmp=(long long)mxg*G+(long long)mxs*S;
		if(tmp<ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}