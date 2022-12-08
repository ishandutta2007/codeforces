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
const int maxn=1001,maxq=100001;
struct A
{
	int kase,x,y,ans;
}ask[maxq];
struct E
{
	int to,next;
}edge[maxq];
int n,m,q,head[maxq],a[maxn][maxn],lazy[maxn],sum[maxn],tot;
void dfs(int u)
{
	bool flag=false;
	int kase=ask[u].kase;
	if(kase==1)
	{
		int x=ask[u].x,y=ask[u].y;
		if(a[x][y]^lazy[x]==0)sum[x]++,flag=true,tot++;
		a[x][y]=lazy[x]^1;
	}
	if(kase==2)
	{
		int x=ask[u].x,y=ask[u].y;
		if(a[x][y]^lazy[x])sum[x]--,flag=true,tot--;
		a[x][y]=lazy[x];
	}
	if(kase==3)
	{
		int x=ask[u].x;
		lazy[x]^=1;
		tot-=sum[x],sum[x]=m-sum[x],tot+=sum[x];
	}
	ask[u].ans=tot;
	for(int i=head[u];i!=-1;i=edge[i].next)dfs(edge[i].to);
	if(kase==1&&flag)
	{
		int x=ask[u].x,y=ask[u].y;
		sum[x]--,tot--;
		a[x][y]=lazy[x];
	}
	if(kase==2&&flag)
	{
		int x=ask[u].x,y=ask[u].y;
		sum[x]++,tot++;
		a[x][y]=lazy[x]^1;
	}
	if(kase==3)
	{
		int x=ask[u].x;
		lazy[x]^=1;
		tot-=sum[x],sum[x]=m-sum[x],tot+=sum[x];
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	read(n),read(m),read(q);
	for(int i=1;i<=q;i++)
	{
		read(ask[i].kase),read(ask[i].x);
		if(ask[i].kase<3)read(ask[i].y);
		int u=ask[i].kase==4?ask[i].x:i-1;
		edge[i]=(E){i,head[u]};
		head[u]=i;
	}
	dfs(0);
	for(int i=1;i<=q;i++)write(ask[i].ans);
	return 0;
}