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
/*const int MOD=
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=300005;

int n,m;
vector<int> G[MAXN];
int fa[MAXN],pa[MAXN],dep[MAXN],od[MAXN];
pii q[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void dfs(int u)
{
	for(auto v:G[u])
		if(v!=pa[u])pa[v]=u,dep[v]=dep[u]+1,dfs(v);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;
	readint(n),readint(E);
	for(int i=1;i<=n;++i)fa[i]=i;
	while(E--)
	{
		int u,v;readint(u),readint(v);
		if(getfa(u)!=getfa(v))G[u].pb(v),G[v].pb(u),fa[getfa(u)]=getfa(v);
	}
	readint(m);
	for(int i=1;i<=m;++i)
	{
		readint(q[i].x),readint(q[i].y);
		od[q[i].x]^=1,od[q[i].y]^=1;
	}
	int cnt=0;
	for(int i=1;i<=n;++i)cnt+=od[i];
	if(cnt)return 0*printf("NO\n%d\n",cnt/2);
	printf("YES\n");
	dfs(1);
	for(int i=1;i<=m;++i)
	{
		int u=q[i].x,v=q[i].y;
		vector<int> a,b;
		while(dep[u]>dep[v])a.pb(u),u=pa[u];
		while(dep[v]>dep[u])b.pb(v),v=pa[v];
		while(u!=v)a.pb(u),u=pa[u],b.pb(v),v=pa[v];
		a.pb(u);
		reverse(b.begin(),b.end());
		printf("%d\n",a.size()+b.size());
		for(auto j:a)printf("%d ",j);
		for(auto j:b)printf("%d ",j);
		putchar('\n');
	}
	return 0;
}