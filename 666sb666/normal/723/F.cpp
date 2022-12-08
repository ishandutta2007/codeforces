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
const int maxn=400005;
struct E
{
	int to,next;
}edge[maxn<<1];
int n,m,head[maxn],s,t,ds,dt,tot=0,fa[maxn],d1=0,d2=0;
bool vis[maxn],isfa[maxn],lk[maxn][2],lnk[maxn][2],lnked[maxn][2];
vector<int>a[maxn];
int x[maxn],y[maxn],total;
inline void addedge(int u,int v)
{
	total++;
	x[total]=u,y[total]=v;
}
int q[maxn<<1];
inline void bfs(int u)
{
	int H=0,T=1;
	q[1]=u;
	vis[u]=true;
	fa[u]=u;
	while(H<T)
	{
		int x=q[++H];
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=s&&edge[i].to!=t&&vis[edge[i].to]==false)
		addedge(x,edge[i].to),vis[edge[i].to]=true,fa[edge[i].to]=u,q[++T]=edge[i].to;
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(isfa,0,sizeof(isfa));
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		edge[++tot]=(E){y,head[x]};
		head[x]=tot;
		edge[++tot]=(E){x,head[y]};
		head[y]=tot;
	}
	read(s),read(t),read(ds),read(dt);
	for(int i=1;i<=n;i++)if(i!=s&&i!=t&&vis[i]==false)bfs(i),isfa[i]=true;
	for(int i=1;i<=n;i++)if(i!=s&&i!=t)a[fa[i]].push_back(i);
	for(int i=head[s];i!=-1;i=edge[i].next)if(edge[i].to!=s&&edge[i].to!=t)lk[fa[edge[i].to]][0]=true,lnk[edge[i].to][0]=true;
	for(int i=head[t];i!=-1;i=edge[i].next)if(edge[i].to!=s&&edge[i].to!=t)lk[fa[edge[i].to]][1]=true,lnk[edge[i].to][1]=true;
	for(int i=1;i<=n;i++)if(isfa[i]&&lk[i][0]==false&&lk[i][1]==false)
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++)if(i!=s&&i!=t&&isfa[i])
	{
		if(lk[i][0]&&lk[i][1]==false)
		{
			d1++;
			if(d1>ds)
			{
				puts("No");
				return 0;
			}
			for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][0])
			{
				addedge(a[i][j],s);
				break;
			}
			lnked[i][0]=true;
		}
		else if(lk[i][1]&&lk[i][0]==false)
		{
			d2++;
			if(d2>dt)
			{
				puts("No");
				return 0;
			}
			for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][1])
			{
				addedge(a[i][j],t);
				break;
			}
			lnked[i][1]=true;
		}
	}
	for(int i=1;i<=n;i++)if(i!=s&&i!=t&&isfa[i])
	{
		if(lk[i][0]&&lk[i][1])
		{
			if(d1<ds)
			{
				d1++;
				for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][0])
				{
					addedge(a[i][j],s);
					break;
				}
				lnked[i][0]=true;
			}
			else if(d2<dt)
			{
				d2++;
				for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][1])
				{
					addedge(a[i][j],t);
					break;
				}
				lnked[i][1]=true;
			}
			else
			{
				puts("No");
				return 0;
			}
		}
	}
	bool flag=false;
	bool st=false;
	for(int i=head[s];i!=-1;i=edge[i].next)if(edge[i].to==t)st=true;
	if(d1<ds&&d2<dt&&st)addedge(s,t),flag=true;
	else
	{
		if(d1>=ds&&d2>=dt)
		{
			puts("No");
			return 0;
		}
		for(int i=1;i<=n;i++)if(i!=s&&i!=t&&isfa[i])
		if(lk[i][0]&&lk[i][1])
		{
			if(lnked[i][0])
			{
				if(d2>=dt)continue;
				d2++;
				for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][1])
				{
					addedge(a[i][j],t);
					break;
				}
				flag=true;
			}
			if(flag)break;
			if(lnked[i][1])
			{
				if(d1>=ds)continue;
				d1++;
				for(int j=0;j<a[i].size();j++)if(lnk[a[i][j]][0])
				{
					addedge(a[i][j],s);
					break;
				}
				flag=true;
			}
			if(flag)break;
		}
	}
	if(!flag)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=total;i++)printf("%d %d\n",x[i],y[i]);
	return 0;
}