#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=405;

int n;
vector<int> G[MAXN];
int dep[MAXN],perm[MAXN];
int lca[MAXN][MAXN],f[MAXN][MAXN],fac[MAXN],ifac[MAXN];
int pa[MAXN];
void dfs(int u)
{
	for(auto v:G[u])
		if(v!=pa[u])dep[v]=dep[u]+1,pa[v]=u,dfs(v);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1,u,v;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	fac[0]=1;for(int i=1;i<=2*n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[2*n]=qmi(fac[2*n],MOD-2);for(int i=2*n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j)
		{
			for(int k=j;k<i+j;++k)
				inc(f[i][j],1ll*fac[i+j-1]*ifac[k]%MOD*ifac[i+j-1-k]%MOD);
			f[i][j]=1ll*f[i][j]*qmi(2,MOD-1-i-j+1)%MOD;
		}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		dep[i]=0;pa[i]=-1;dfs(i);
		for(int j=1;j<=n;++j)perm[j]=j;
		sort(perm+1,perm+n+1,[&](int x,int y){return dep[x]<dep[y];});
		for(int xx=1;xx<=n;++xx)
			for(int yy=1;yy<=n;++yy)
			{
				int x=perm[xx],y=perm[yy];
				if(x==y)lca[x][y]=x;
				else if(dep[x]>dep[y])lca[x][y]=lca[pa[x]][y];
				else lca[x][y]=lca[x][pa[y]];
			}
		for(int x=1;x<=n;++x)
			for(int y=x+1;y<=n;++y)
			{
				int s=dep[x]-dep[lca[x][y]],t=dep[y]-dep[lca[x][y]];
				inc(ans,f[s][t]);
			}
	}
	ans=1ll*ans*qmi(n,MOD-2)%MOD;
	printf("%d\n",ans);
	return 0;
}