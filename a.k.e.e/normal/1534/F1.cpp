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
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=400005;

int n,m;
char s[MAXN];
int a[MAXN],dw[MAXN];
vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],dfn_cnt,sta[MAXN],top,k,scc[MAXN],deg[MAXN];
void tarjan(int u)
{
	dfn[u]=low[u]=++dfn_cnt;
	sta[++top]=u;
	for(auto v:G[u])
		if(!dfn[v])tarjan(v),chkmin(low[u],low[v]);
		else if(!scc[v])chkmin(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{
		++k;
		do
		{
			u=sta[top--];
			scc[u]=k;
		}while(dfn[u]!=low[u]);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=0;i<n;++i)scanf("%s",s+i*m);
	for(int i=0;i<m;++i)readint(a[i]);
	for(int j=0;j<m;++j)
	{
		dw[n*m+j]=n;
		for(int i=n-1;i>=0;--i)dw[i*m+j]=(s[i*m+j]=='#'?i:dw[(i+1)*m+j]);
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int u;
			if(i)u=dw[(i-1)*m+j],u<n?G[i*m+j].pb(u*m+j):void(0);
			if(i<n-1)u=dw[(i+1)*m+j],u<n?G[i*m+j].pb(u*m+j):void(0);
			if(j)u=dw[i*m+j-1],u<n?G[i*m+j].pb(u*m+j-1):void(0);
			if(j<m-1)u=dw[i*m+j+1],u<n?G[i*m+j].pb(u*m+j+1):void(0);
		}
	for(int i=0;i<n*m;++i)if(!dfn[i] && s[i]=='#')tarjan(i);
	for(int i=0;i<n*m;++i)
		if(s[i]=='#')
		{
			for(auto j:G[i])
				if(scc[j]!=scc[i])++deg[scc[j]];
		}
	int res=0;
	for(int i=1;i<=k;++i)
		if(!deg[i])++res;
	printf("%d\n",res);
	return 0;
}