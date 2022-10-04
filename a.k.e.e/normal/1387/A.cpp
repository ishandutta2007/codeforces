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
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=100005;

int n,m;
vector<pii> G[MAXN];
int col[MAXN],from[MAXN],fval[MAXN];
bool vis[MAXN];
double val[MAXN];
pair<double,int> mv[MAXN];
pair<pii,int> color(int u)
{
	for(int i=0;i<G[u].size();++i)
	{
		int v=G[u][i].x,c=G[u][i].y;
		if(col[v]==col[u])return mp(mp(u,v),c);
		if(!col[v])
		{
			from[v]=u,fval[v]=c;
			col[v]=3-col[u];
			pair<pii,int> p=color(v);
			if(p.x.x)return p;
		}
	}
	return mp(mp(0,0),0);
}
bool dfs(int u)
{
	vis[u]=1;
	mv[++m]=mp(col[u]==1?val[u]:-val[u],u);
	for(int i=0;i<G[u].size();++i)
	{
		int v=G[u][i].x,c=G[u][i].y;
		if(vis[v] && fabs(val[u]+val[v]-c)>1e-9)return 0;
		if(!vis[v])
		{
			val[v]=c-val[u];
			if(!dfs(v))return 0;
		}
	}
	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,u,v,c;
	readint(n),readint(Q);
	while(Q--)readint(u),readint(v),readint(c),G[u].pb(mp(v,c)),G[v].pb(mp(u,c));
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		col[i]=1;
		pair<pii,int> p=color(i);
		u=p.x.x,v=p.x.y,c=p.y;
		if(!u)u=v=i,c=0;
		int sum=c,s2=0;
		for(int x=u,d=0;x!=v;x=from[x],d^=1)sum+=fval[x],s2+=d*fval[x];
		val[u]=sum*0.5-s2;
		m=0;
		if(!dfs(u))return 0*printf("NO\n");
		if(!c)
		{
			sort(mv+1,mv+m+1);
			double md=mv[(m+1)/2].x;
			for(int i=1;i<=m;++i)
			{
				if(col[mv[i].y]==1)val[mv[i].y]-=md;
				else val[mv[i].y]+=md;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i)printf("%.9lf ",val[i]);
	return 0;
}