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
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=200005;

int n,whi[MAXN],fib[MAXN];
vector<int> G[MAXN];
int vis[MAXN],stot;
int sz[MAXN];
vector<pii> res;
void dfs(int u,int pa,int w)
{
	sz[u]=1;
	for(auto v:G[u])
	{
		if(v==pa || vis[v])continue;
		dfs(v,u,w);
		if(sz[v]==fib[w-1])res.pb(mp(u,v));
		if(sz[v]==fib[w-2])res.pb(mp(v,u));
		sz[u]+=sz[v];
	}
}
void makevis(int u,int pa,int c)
{
	vis[u]+=c;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		if(c>0 && !vis[v])makevis(v,u,c);
		else if(vis[v]==-c)makevis(v,u,c);
	}
}
bool solve(int w,int u)
{
	if(w<=2)return 1;
	res.clear();
	dfs(u,-1,w);
//cerr<<w<<" "<<u<<" "<<res.size()<<" ; ";for(int i=1;i<=n;++i)if(!vis[i])cerr<<i<<" ";cerr<<endl;
	if(res.empty())return 0;
//for(auto v:res)cerr<<v.x<<" "<<v.y<<endl;
	if(res.size()==1)
	{
		pii a=res[0];
		int t=++stot;
		makevis(a.y,a.x,t);
		bool za=solve(w-2,a.x);
		makevis(a.y,a.x,-t);
		if(!za)return 0;
		t=++stot;
		makevis(a.x,a.y,t);
		bool r=solve(w-1,a.y);
		makevis(a.x,a.y,-t);
		return r;
	}
	pii a=res[0],b=res[1];
	int t=++stot;
	makevis(a.y,a.x,t);
	bool za=solve(w-2,a.x);
	makevis(a.y,a.x,-t);
	t=++stot;
	makevis(b.y,b.x,t);
	bool zb=solve(w-2,b.x);
	makevis(b.y,b.x,-t);
	if(!za || !zb)return 0;
	t=++stot;
	makevis(a.x,a.y,t);
	makevis(b.x,b.y,t);
	bool r=solve(w-3,a.y);
	makevis(a.x,a.y,-t);
	makevis(b.x,b.y,-t);
	return r;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	fib[0]=fib[1]=1;
	for(int i=2;fib[i-1]+fib[i-2]<=n;++i)fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;fib[i];++i)whi[fib[i]]=i;
	printf( (whi[n] && solve(whi[n],1)) ?"YES\n":"NO\n");
	return 0;
}