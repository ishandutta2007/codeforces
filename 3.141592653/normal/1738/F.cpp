#include<bits/stdc++.h>
using std::min;
using std::max;
typedef long long ll;

int n,r,k,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
std::map<ll,int>M;
const int mod = 998244353 ;
int fac[1<<20],inv[1<<20];
int qpow(int x,int k)
{
	int r=1;
	for(;k;k>>=1,x=x*1ll*x%mod)
		if(k&1)r=r*1ll*x%mod;
	return r;
}
int C(int n,int r)
{
	return fac[n]*1ll*inv[r]%mod*inv[n-r]%mod;
}
int calc(int x,int y,int i)
{
	return C(x,i)*1ll*C(y,i)%mod;
}
std::vector<int>v[1<<20];
int col[1<<20];
bool vis[1<<20];
void test(int p)
{
	vis[p]=1;
	for(int i=1;i<=d[p];i++)
	{
		int t;
		printf("? %d\n",p);
		fflush(stdout);
		scanf("%d",&t);
		v[t].push_back(p);
		v[p].push_back(t);
		if(vis[t])return;
		vis[t]=1;
	}
}
void dfs(int p,int c)
{
	col[p]=c;
	vis[p]=1;
	for(int t:v[p])if(!vis[t])dfs(t,c);
} 
void exec()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",d+i);
		a[i]=i;
		v[i].clear();
		vis[i]=0;
	}
	std::sort(a+1,a+n+1,[&](int x,int y){return d[x] > d[y];});
	for(int i=1;i<=n;i++)
		if(!vis[a[i]])
			test(a[i]);
	for(int i=1;i<=n;i++)
		vis[i]=0;
	int cl=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cl++,dfs(i,cl);
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %d",col[i]);
	puts("");fflush(stdout);	
}

int main()
{
	for(int i=fac[0]=1;i<=1e6;i++)
		fac[i]=fac[i-1]*1ll*i%mod;
	inv[1000000]=qpow(fac[1000000],mod-2);
	for(int i=1e6;i;i--)
		inv[i-1]=inv[i]*1ll*i%mod;
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}