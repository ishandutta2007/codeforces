#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
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
const int INF=0x3f3f3f3f;
const int MAXN=100005;

int n;
vector<int> G[MAXN];
int s[MAXN],a[MAXN];
void dfs(int u,int pa)
{
	a[u]=s[u];
	for(auto v:G[u])
		if(v!=pa)
			s[v]=-s[u],dfs(v,u),a[u]-=s[v];
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1,u,v;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	s[1]=1;dfs(1,-1);
	a[1]=0;for(auto v:G[1])a[1]-=s[v];
	for(int i=1;i<=n;++i)printf("%d ",a[i]);putchar('\n');
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