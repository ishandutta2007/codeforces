#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
int inv(int x){return qmi(x,MOD-2);}*/
const int MAXN=605;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n;
ll a[MAXN][MAXN],pre[MAXN][MAXN],suf[MAXN][MAXN];
ll f[MAXN];
bool vis[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;
	readint(n);readint(E);memset(a,0x3f,sizeof(a));
	for(int u,v;E;--E)readint(u),readint(v),readint(a[u][v]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			pre[i][j]=min(a[i][j]-j,j?pre[i][j-1]:INF);
		suf[i][n]=INF;
		for(int j=n-1;j>=0;--j)
			suf[i][j]=min(a[i][j]-j,suf[i][j+1]);
	}
	for(int i=0;i<n;++i)
	{
		memset(f,0x3f,sizeof(f));
		memset(vis,0,sizeof(vis));
		f[i]=0;
		for(int t=0;t<n-1;++t)
		{
			int u=-1;
			for(int j=0;j<n;++j)
				if(!vis[j] && (u<0 || f[j]<f[u]))
					u=j;
			vis[u]=1;
			for(int j=0;j<n;++j)
				if(!vis[j])
				{
					int x=(j-f[u]%n+n)%n;
					chkmin(f[j],f[u]+pre[u][x]+x);
					chkmin(f[j],f[u]+suf[u][x]+x+n);
				}
		}
		for(int j=0;j<n;++j)printf("%lld ",f[j]);
		putchar('\n');
	}
	return 0;
}