#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=605;
LL f[N][N];
LL n,m,q;
LL X[N*N],Y[N*N],W[N*N];
LL XX[N*N],YY[N*N],WW[N*N];
bool in[N*N];
LL mx[N][N];
void solve ()
{
	for (int u=1;u<=m;u++)
	{
		for (int y=1;y<=n;y++)
		{
			if (mx[X[u]][y]>=f[y][Y[u]]+W[u]) in[u]=true;
			if (mx[Y[u]][y]>=f[y][X[u]]+W[u]) in[u]=true;
			//vec[X[u]][y].push_back(make_pair(f[y][Y[u]]+W[u],u));
			//vec[Y[u]][y].push_back(make_pair(f[y][X[u]]+W[u],u));
		}
	}
}
int main()
{
	memset(in,false,sizeof(in));
	memset(f,63,sizeof(f));
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<=n;u++) f[u][u]=0;
	for (LL u=1;u<=m;u++)
	{
		LL x,y,w;
		scanf("%lld%lld%lld",&x,&y,&w);
		X[u]=x;Y[u]=y;W[u]=w;
		f[x][y]=f[y][x]=w;
	}
	for (LL u=1;u<=n;u++)
	for (LL i=1;i<=n;i++)
	for (LL j=i+1;j<=n;j++)
	{
		f[i][j]=min(f[i][j],f[i][u]+f[u][j]);
		f[j][i]=f[i][j];
	}
	scanf("%lld",&q);
	for (LL i=1;i<=q;i++)
	{
		LL x,y,l;
		scanf("%lld%lld%lld",&x,&y,&l);
		for (int j=1;j<=n;j++)	mx[j][y]=max(mx[j][y],l-f[x][j]);
	}
	solve();
	LL ans=0;
	for (LL u=1;u<=m;u++) ans=ans+in[u];
	printf("%lld\n",ans);
	return 0;
}