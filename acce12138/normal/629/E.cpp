//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
//  Don't copy my code, because my coding style is easy to recognize.
//  I hope my code will get 'Accepted'!

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define mem(x,y) memset((x),(y),sizeof(x))
#define abs(x) ((x)>0?(x):(-x))
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LF;
typedef pair<int,int> pii;

const int inf=0x7fffffff;
const LL Linf=1ll<<61;
const double EPS=1e-10;

void get_int(int &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
void get_int(LL &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
void print_int(int x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
void print_int(LL x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}

const int maxlog=20;
const int maxn=100005;
int n;
vector<int> g[maxn];

int f[maxlog][maxn],dep[maxn],sz[maxn];
LL cnt[maxn],cnt2[maxn];
void dfs(int x,int fa,int d)
{
	f[0][x]=fa;
	dep[x]=d;
	sz[x]=1;
	for(int i=0; i<(int)g[x].size(); i++)
		if(g[x][i]!=fa)
		{
			dfs(g[x][i],x,d+1);
			sz[x]+=sz[g[x][i]];
			cnt[x]+=cnt[g[x][i]];
		}
	cnt[x]+=sz[x]-1;
}
void dfs2(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f[0][x])
		{
			cnt2[g[x][i]]=cnt2[x]+cnt[x]-cnt[g[x][i]]+n-2*sz[g[x][i]];
			dfs2(g[x][i]);
		}
}
void build()
{
	dfs(1,0,0);
	for(int i=1; i<maxlog; i++)
		for(int j=1; j<=n; j++)
			f[i][j]=f[i-1][f[i-1][j]];
	dfs2(1);
}
int query(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int dif=dep[x]-dep[y];
	for(int i=0; i<maxlog; i++)
		if((dif>>i)&1)
			x=f[i][x];
	if(x==y)return x;
	for(int i=maxlog-1; i>=0; i--)
		if(f[i][x]!=f[i][y])
		{
			x=f[i][x];
			y=f[i][y];
		}
	return f[0][x];
}
int up(int x,int y)
{
	for(int i=0;i<maxlog;i++)
		if((y>>i)&1)x=f[i][x];
	return x;
}
int m;
void prework()
{
	get2(n,m);
	for(int i=1,u,v; i<n; i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	build();
}
void answer()
{
	LL ways,ans;
	for(int i=1,u,v,lca,path; i<=m; i++)
	{
		get2(u,v);
		lca=query(u,v);
		path=dep[u]+dep[v]-dep[lca]*2;
		ans=0;
		if(lca!=u&&lca!=v)
		{
			ways=sz[u]*1ll*sz[v];
			ans=path*ways+cnt[u]*sz[v]+cnt[v]*sz[u];
		}
		else
		{
			if(lca==u)swap(u,v);
			int tmp=up(u,dep[u]-dep[v]-1);
			ways=sz[u]*1ll*(n-sz[tmp]);
			ans=path*ways+(n-sz[tmp])*cnt[u]+sz[u]*(cnt2[v]+cnt[v]-cnt[tmp]-sz[tmp]);
		}
		printf("%.10lf\n",ans*1.0/ways+1);
	}
}

int main()
{
	prework();
	answer();
	return 0;
}