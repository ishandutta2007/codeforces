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
const int MAXN=800005;

int n,m,o;
char s[MAXN];
int a[MAXN],dw[MAXN];
vector<int> G[MAXN],H[MAXN];
int dfn[MAXN],low[MAXN],dfn_cnt,sta[MAXN],top,k,scc[MAXN],deg[MAXN];
int nd[MAXN],hv[MAXN];
int q[MAXN],g[MAXN];
pii wt[MAXN];
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
		int k=a[j];a[j]=n;
		for(int i=n-1;i>=0 && k;--i)if(s[i*m+j]=='#')--k,a[j]=i;
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
				if(scc[j]!=scc[i])H[scc[i]].pb(scc[j]);
		}
	for(int j=0;j<m;++j)
		nd[scc[a[j]*m+j]]=j+1;
	for(int i=1;i<=k;++i)
	{
		sort(H[i].begin(),H[i].end());
		int o=unique(H[i].begin(),H[i].end())-H[i].begin();
		while(H[i].size()>o)H[i].pop_back();
	}
	int front=1,rear=0;
	for(int i=1;i<=k;++i)for(auto j:H[i])++deg[j];
	for(int i=1;i<=k;++i)if(!deg[i])q[++rear]=i;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto v:H[u])
		{
			hv[v]|=(hv[u]||nd[u]);
			--deg[v];
			if(!deg[v])q[++rear]=v;
		}
	}
	vector<int> alnd;
	for(int i=1;i<=k;++i)
	{
		if(hv[i])nd[i]=0;
		if(nd[i])alnd.pb(nd[i]);
	}
	sort(alnd.begin(),alnd.end());
	int o=alnd.size();
	for(int i=1;i<=k;++i)
		if(nd[i])
		{
			nd[i]=lower_bound(alnd.begin(),alnd.end(),nd[i])-alnd.begin()+1;
			wt[i]=mp(nd[i],nd[i]);
		}
		else wt[i]=mp(o+1,0);
	for(int ii=k;ii;--ii)
	{
		int i=q[ii];
		for(auto j:H[i])
			chkmin(wt[i].x,wt[j].x),chkmax(wt[i].y,wt[j].y);
		chkmax(g[wt[i].x],wt[i].y+1);
	}
	for(int i=1;i<o;++i)chkmax(g[i+1],g[i]);

	int res=0;
	for(int i=1;i<=o;i=g[i])++res;
	printf("%d\n",res);
	return 0;
}