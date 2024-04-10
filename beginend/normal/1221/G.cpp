#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=45;
const int M=1048580;

int n,m,cnt,last[N],p,col[N],f[M],ma1[N],ma2[N],ma3[M];
LL bin[N];
bool vis[N],flag;
struct edge{int to,next;}e[N*N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	vis[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to]) col[e[i].to]=col[x]^1,dfs(e[i].to);
		else if (col[x]==col[e[i].to]) flag=1;
}

LL calc()
{
	for (int i=1;i<=m;i++)
	{
		int x=e[i*2-1].to,y=e[i*2].to;
		if (x>y) std::swap(x,y);
		if (x<=p&&y<=p) ma1[x-1]^=bin[y-1],ma1[y-1]^=bin[x-1];
		else if (x>p&&y>p) ma2[x-p-1]^=bin[y-p-1],ma2[y-p-1]^=bin[x-p-1];
		else ma3[bin[x-1]]^=bin[y-p-1];
	}
	for (int i=0;i<bin[n-p];i++)
	{
		f[i]=1;
		for (int j=0;j<n-p;j++)
			if ((i&bin[j])&&(i&ma2[j])) {f[i]=0;break;}
	}
	for (int i=0;i<n-p;i++)
		for (int j=bin[n-p]-1;j>=0;j--)
			if (j&bin[i]) f[j]+=f[j^bin[i]];
	for (int i=0;i<p;i++)
		for (int j=bin[p]-1;j>=0;j--)
			if (j&bin[i]) ma3[j]|=ma3[j^bin[i]];
	LL ans=0;
	for (int i=0;i<bin[p];i++)
	{
		bool flag=0;
		for (int j=0;j<p;j++)
			if ((i&bin[j])&&(i&ma1[j])) {flag=1;break;}
		if (flag) continue;
		ans+=f[(bin[n-p]-1)^ma3[i]];
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	p=n/2;
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	LL ans=bin[n];			//0,1,2
	int s1=0,s2=0;
	for (int i=1;i<=n;i++) if (!vis[i]) vis[i]=1,dfs(i),s1++;
	for (int i=1;i<=n;i++) if (!last[i]) s2++;
	ans-=bin[s1];			//0,2
	ans+=bin[s2];			//2
	if (!flag) ans+=bin[s1];//1
	ans+=bin[s2];			//0
	if (!m) ans-=bin[n];	//
	ans-=calc()*2;			//0,1 1,2
	printf("%lld\n",ans);
	return 0;
}