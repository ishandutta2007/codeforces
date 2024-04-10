#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a,b,cnt,head[200003],dp[200003],in[200003];
struct edge{
	int t,next;
}ed[400007];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	in[f]++;
}
void dfs(int u,int fa,int k)
{
	int tmp=0;
	if(in[u]==0)m++,tmp=1;
	if(k==1&&in[u])
	tmp=19260817;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u,!k);
		if(k)
		tmp=min(tmp,dp[ed[i].t]);
		else
		tmp+=dp[ed[i].t];
	}
	dp[u]=tmp;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	dfs(1,0,1);
	printf("%d ",m-dp[1]+1);
	memset(dp,0,sizeof dp);
	m=0;
	dfs(1,0,0);
	printf("%d\n",dp[1]);
}
//emmm