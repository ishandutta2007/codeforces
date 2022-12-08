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
const int maxn=5005;
struct E
{
	int to,v,next;
}edge[maxn];
int n,m,t,head[maxn],f[maxn][maxn],vis[maxn],in[maxn];
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		if(!vis[edge[i].to])dfs(edge[i].to);
		for(int j=1;j<=n;j++)f[u][j]=min(f[u][j],f[edge[i].to][j-1]+edge[i].v);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	read(n),read(m),read(t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		edge[i]=(E){y,z,head[x]};
		head[x]=i;
		in[y]++;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)f[i][j]=1e9+5;
	f[n][0]=0;
	for(int i=1;i<=n;i++)if(!in[i])dfs(i);
	int tot=0;
	for(int i=n;i>=0;i--)if(f[1][i]<=t)
	{
		tot=i+1;
		break;
	}
	write(tot);
	int now=1,step=1;
	printf("1 ");
	while(now!=n)
	{
		for(int i=head[now];i!=-1;i=edge[i].next)if(f[now][tot-step]==f[edge[i].to][tot-step-1]+edge[i].v)
		{
			printf("%d ",edge[i].to);
			now=edge[i].to;
			step++;
			break;
		}
	}
	return 0;
}