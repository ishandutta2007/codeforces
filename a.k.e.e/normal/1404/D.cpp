#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
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
const int MAXN=1000005;

int n;
int p[MAXN],a[MAXN][2];
vector<int> G[MAXN];
bool res[MAXN],vis[MAXN];
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(auto v:G[u])
		res[v]=!res[u],dfs(v);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int x;
	readint(n);
	if(n&1)
	{
		printf("Second\n");
		fflush(stdout);
		for(int i=1;i<=2*n;++i)
		{
			readint(p[i]);
			if(a[p[i]][0])a[p[i]][1]=i;
			else a[p[i]][0]=i;
		}
		for(int i=1;i<=n;++i)
		{
			int u=a[i][0],v=a[i][1];
			G[u].pb(v),G[v].pb(u);
		}
		for(int i=1;i<=n;++i)
		{
			int u=i,v=i+n;
			G[u].pb(v),G[v].pb(u);
		}
		for(int i=1;i<=2*n;++i)
			if(!vis[i])dfs(i);
		int sum=0;
		for(int i=1;i<=2*n;++i)if(res[i])sum=(sum+i)%(2*n);
		if(sum)for(int i=1;i<=2*n;++i)res[i]=!res[i];
		for(int i=1;i<=2*n;++i)if(res[i])printf("%d ",i);
	}
	else
	{
		printf("First\n");
		for(int i=1;i<=2*n;++i)printf("%d ",(i-1)%n+1);
		fflush(stdout);
	}
	return 0;
}