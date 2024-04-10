#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005,md=998244353;
int n,i,j,f[N][2],head[N],adj[N],nxt[N];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void dfs(int x)
{
	if(!head[x])
	{
		f[x][0]=f[x][1]=1;
		return;
	}
	f[x][0]=1;
	int w=1;
	for(int y=head[x];y;y=nxt[y])
	{
		dfs(adj[y]);
		w=1ll*w*f[adj[y]][0]%md;
		f[x][0]=1ll*f[x][0]*(f[adj[y]][0]+f[adj[y]][1])%md;
	}
	f[x][1]=(f[x][0]-w+md)%md;
	for(int y=head[x];y;y=nxt[y])
		f[x][0]=(f[x][0]-1ll*w*pw(f[adj[y]][0],md-2)%md*f[adj[y]][1]%md+md)%md;
}
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&j);
		adj[i-1]=i;
		nxt[i-1]=head[j];
		head[j]=i-1;
	}
	dfs(1);
	printf("%d",f[1][0]);
	return 0;
}