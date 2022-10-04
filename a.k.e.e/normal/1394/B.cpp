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
const int MAXN=200005,MAXK=11;

int n,k;
vector<pii> G[MAXN];
int f[MAXN][MAXK][MAXK];
bool g[MAXK][MAXK][MAXK][MAXK];
int cur[MAXK],ans=0;
void dfs(int u)
{
	if(u>k){++ans;return;}
	for(int i=1;i<=u;++i)
	{
		if(g[u][i][u][i])continue;
		bool flag=1;
		for(int v=1;v<u;++v)
			if(g[u][i][v][cur[v]]){flag=0;break;}
		if(!flag)continue;
		cur[u]=i;
		dfs(u+1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v,c;
	readint(n),readint(E),readint(k);
	while(E--)
	{
		readint(u),readint(v),readint(c);
		G[u].pb(mp(c,v));
	}
	for(int i=1;i<=n;++i)
	{
		sort(G[i].begin(),G[i].end());
		for(int j=0;j<G[i].size();++j)f[G[i][j].y][G[i].size()][j+1]++;
	}
	for(int i=1;i<=n;++i)
		for(int x=1;x<=k;++x)
			for(int y=1;y<=x;++y)
			{
				if(!f[i][x][y])continue;
//cerr<<i<<" "<<x<<" "<<y<<endl;
				for(int u=1;u<x;++u)
					for(int v=1;v<=u;++v)
						if(f[i][u][v])g[x][y][u][v]=1;
				if(f[i][x][y]>=2)g[x][y][x][y]=1;
			}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}