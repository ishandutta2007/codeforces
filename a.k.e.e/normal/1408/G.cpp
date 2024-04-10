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
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1505,MAXM=12005;

int n,a[MAXN][MAXN],p[MAXN];
int Min[MAXN],bef[MAXN],cnt[MAXN];
int m,fa[MAXM];
int f[MAXM][MAXN],sz[MAXM];
vector<int> G[MAXM];
void dfs(int u)
{
	if(G[u].empty()){sz[u]=f[u][1]=1;return;}
	f[u][0]=1;
	for(auto v:G[u])
	{
		dfs(v);
		for(int i=sz[u]+sz[v];i>=0;--i)
		{
			f[u][i]=0;
			for(int j=min(sz[v],i);j && i-j<=sz[u];--j)
				inc(f[u][i],1ll*f[u][i-j]*f[v][j]%MOD);
		}
		sz[u]+=sz[v];
	}
	inc(f[u][1],1);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)readint(a[i][j]),p[j-(j>i)]=a[i][j];
		sort(p+1,p+n);
		for(int j=1;j<=n;++j)if(i!=j)a[i][j]=lower_bound(p+1,p+n,a[i][j])-p;
	}
	for(int i=1;i<=n;++i)Min[i]=n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)p[a[i][j]]=j,cnt[j]=0;
		int sum=0,las=++m,fin=0;
		for(int j=1;j<Min[i];++j)
		{
			int u=p[j];
			sum+=cnt[j];
			for(int k=0;k<j;++k)
			{
				++cnt[a[u][p[k]]];if(a[u][p[k]]>=Min[i]){sum=-1;break;}if(a[u][p[k]]<=j)++sum;
				++cnt[a[p[k]][u]];if(a[p[k]][u]>=Min[i]){sum=-1;break;}if(a[p[k]][u]<=j)++sum;
			}
			if(sum<0)break;
			if(sum==(j+1)*j)
			{
				fa[las]=++m;
				las=m;
				for(int k=fin+1;k<=j;++k)bef[p[k]]=m,Min[p[k]]=j;
				fin=j;
			}
		}
		fa[las]=bef[i];
	}
	for(int i=1;i<=m;++i)G[fa[i]].pb(i);
	dfs(G[0][0]);
	for(int i=1;i<=n;++i)printf("%d ",f[G[0][0]][i]);
	return 0;
}