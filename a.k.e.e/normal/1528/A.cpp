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
const int MAXN=200005;

int n,a[MAXN][2];
vector<int> G[MAXN];
ll f[MAXN][2];
void dfs(int u,int pa)
{
	for(int i=0;i<=1;++i)f[u][i]=0;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs(v,u);
		for(int i=0;i<=1;++i)
		{
			ll res=0;
			for(int j=0;j<=1;++j)
				chkmax(res,f[v][j]+abs(a[u][i]-a[v][j]));
			f[u][i]+=res;
		}
	}
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i][0]),readint(a[i][1]),G[i].clear();
	for(int i=1,u,v;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	dfs(1,-1);
	printf("%lld\n",max(f[1][0],f[1][1]));
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}