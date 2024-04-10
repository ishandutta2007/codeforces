#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=200005;
const int MOD=1000000007;

int n,a[N],cnt,last[N],phi[N],mu[N],prime[N],tot,g[N],s1[N],s2[N],f[N],root,sum,size[N],top,stack[N],dep[N];
bool not_prime[N],vis[N];
struct edge{int to,next;}e[N*2];
std::vector<int> vec[N],rub;

int add(int x,int y) {return x+y<MOD?x+y:x+y-MOD;}
int dec(int x,int y) {return x-y<0?x-y+MOD:x-y;}
int mul(int x,int y) {return (LL)x*y%MOD;}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void get_prime(int n)
{
	mu[1]=phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,phi[i]=i-1,mu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			mu[i*prime[j]]=-mu[i];
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}

void get_root(int x,int fa)
{
	size[x]=1;f[x]=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa||vis[e[i].to]) continue;
		get_root(e[i].to,x);
		size[x]+=size[e[i].to];
		f[x]=std::max(f[x],size[e[i].to]);
	}
	f[x]=std::max(f[x],sum-size[x]);
	if (!root||f[x]<f[root]) root=x;
}

void get(int x,int fa)
{
	stack[++top]=x;size[x]=1;dep[x]=dep[fa]+1;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]) get(e[i].to,x),size[x]+=size[e[i].to];
}

void solve(int x)
{
	vis[x]=1;
	for (int i=0;i<vec[a[x]].size();i++) s1[vec[a[x]][i]]=add(s1[vec[a[x]][i]],phi[a[x]]),rub.pb(vec[a[x]][i]);
	dep[x]=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		top=0;
		get(e[i].to,x);
		for (int j=1;j<=top;j++)
			for (int k=0;k<vec[a[stack[j]]].size();k++)
			{
				int y=stack[j],p=vec[a[y]][k];
				rub.pb(p);
				g[p]=add(g[p],mul(phi[a[y]],add(s2[p],mul(s1[p],dep[y]))));
			}
		for (int j=1;j<=top;j++)
			for (int k=0;k<vec[a[stack[j]]].size();k++)
			{
				int y=stack[j],p=vec[a[y]][k];
				rub.pb(p);
				s1[p]=add(s1[p],phi[a[y]]);s2[p]=add(s2[p],mul(phi[a[y]],dep[y]));
			}
	}
	for (int i=0;i<rub.size();i++) s1[rub[i]]=s2[rub[i]]=0;
	rub.clear();
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		root=0;sum=size[e[i].to];
		get_root(e[i].to,x);
		solve(root);
	}
}

int main()
{
	scanf("%d",&n);
	get_prime(n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			vec[j].pb(i);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	sum=n;root=0;
	get_root(1,0);
	solve(root);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=i;j<=n;j+=i) (s+=(LL)g[j]*mu[j/i]%MOD)%=MOD;
		(ans+=(LL)s*i%MOD*ksm(phi[i],MOD-2)%MOD)%=MOD;
	}
	ans=(ans*2%MOD+MOD)%MOD;
	printf("%d\n",(LL)ans*ksm((LL)n*(n-1)%MOD,MOD-2)%MOD);
	return 0;
}