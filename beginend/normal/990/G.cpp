#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

typedef long long LL;

const int N=200005;

int n,cnt,last[N],mu[N],prime[N],tot,f[N],s[N],a[N],t[N];
bool not_prime[N];
std::vector<int> vec[N];
struct edge{int x,y;}e[N];
LL g[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void get_prime(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
}

void preg(int m)
{
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=i;j<=m;j+=i)
		{
			g[i]+=t[j];
			for (int k=0;k<vec[j].size();k++)
			{
				int x=e[vec[j][k]].x,y=e[vec[j][k]].y;
				x=find(x);y=find(y);
				g[i]+=(LL)s[x]*s[y];
				f[x]=y;s[y]+=s[x];
			}
		}
		for (int j=i;j<=m;j+=i)
			for (int k=0;k<vec[j].size();k++)
			{
				int x=e[vec[j][k]].x,y=e[vec[j][k]].y;
				f[x]=x;f[y]=y;s[x]=s[y]=1;
			}
	}
}

void solve(int m)
{
	for (int i=1;i<=m;i++)
	{
		LL ans=0;
		for (int j=i;j<=m;j+=i) ans+=(LL)g[j]*mu[j/i];
		if (ans) printf("%d %I64d\n",i,ans);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),t[a[i]]++;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[i].x=x;e[i].y=y;
		int d=gcd(a[x],a[y]);
		vec[d].push_back(i);
	}
	get_prime(200000);
	preg(200000);
	solve(200000);
	return 0;
}