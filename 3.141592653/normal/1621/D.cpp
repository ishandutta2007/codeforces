#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1<<20;
int n,N,N3;
ll f[1<<10][1<<10],s[1<<10][1<<10],t[1<<10][1<<10];
struct pii{int x,y;ll len;};
bool operator<(const pii&x,const pii&y)
{
	return x.len>y.len;
}
std::priority_queue<pii>Q;
ll dis[1<<10][1<<10];
ll g[1<<10][1<<10];

ll solve()
{
	ll ret=1e18;
	return std::min(std::min(g[1][1],g[1][n]),std::min(g[n][1],g[n][n]));
	for(int i=1;i<=n;i++)
		for(int ii=1;ii<=n;ii++)
		{
			s[i][ii]=g[i][ii]+s[i][ii-1],
			t[i][ii]=g[i][ii]+t[i-1][ii];
		}
	for(int i=1;i<=n;i++)
		for(int ii=1;ii<=n;ii++)
		{
			if(i!=1||i!=n)continue;
			
			ll minx=std::min(s[i][ii-1],s[i][n]-s[i][ii]);
			ll miny=std::min(t[i-1][ii],t[n][ii]-t[i][ii]);
			ret=std::min(ret,g[i][ii]+minx+miny);
		}
	return ret;
}
void exec()
{
	scanf("%d",&n);
	N=n<<1,N3=n*3;
	ll Ss=0;
	for(int i=1;i<=N;i++)
		for(int ii=1;ii<=N;ii++)
		{
			scanf("%lld",f[i]+ii);
			if(ii>n&&i>n)
			{
				Ss+=f[i][ii];
				f[i][ii]=0;
			}
		}
	for(int i=1;i<=n;i++)
		for(int ii=1;ii<=n;ii++)
			g[i][ii]=f[i+n][ii];
	ll ans=solve();
	for(int i=1;i<=n;i++)
		for(int ii=1;ii<=n;ii++)
			g[i][ii]=f[i][ii+n];
	ans=std::min(ans,solve());
	printf("%lld\n",ans+Ss);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}