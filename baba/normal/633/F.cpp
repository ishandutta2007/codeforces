//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(1e5)+10;
VI g[N];
LL A[N],dp2[N],dp[N],up[N],up2[N];
void dfs(int u,int p)
{
	dp2[u]=dp[u]=A[u];
	vector<LL> x;
	for(auto w:g[u])
		if(w!=p)
		{
			dfs(w,u);
			x.PB(dp2[w]);
		}
	if(x.empty())return;
	x.PB(0);sort(ALL(x));reverse(ALL(x));
	dp2[u]+=x[0];dp[u]=x[0]+x[1]+A[u];
	for(auto w:g[u])
		if(w!=p)
			dp[u]=max(dp[u],dp[w]);
}
void dfs2(int u,int p)
{
	vector<LL> x,y;
	for(auto w:g[u])
	{
		if(w==p)continue;
		x.PB(dp2[w]);y.PB(dp[w]);
	}
	if(x.empty())return;
	x.PB(0);x.PB(0);sort(ALL(x));reverse(ALL(x));
	y.PB(0);sort(ALL(y));reverse(ALL(y));
	for(auto w:g[u])
	{
		if(w==p)continue;
		up2[w]=max(up2[u]+A[w],A[u]+A[w]+(x[0]==dp2[w]?x[1]:x[0]));
		up[w] = max(y[0]==dp[w]?y[1]:y[0],A[u] + (x[0]==dp2[w]?x[1]+x[2]:(x[1]==dp2[w]?x[0]+x[2]:x[0]+x[1])));
		up[w] = max(up[w], up[u]);
		up[w] = max(up[w], up2[u]+(x[0]==dp2[w]?x[1]:x[0]));
		dfs2(w,u);
	}
}
int main()
{
	int n;si(n);
	for(int i=1;i<=n;i++)sll(A[i]);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		si(u);si(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,1);
	up2[1]=A[1];
	dfs2(1,1);
	LL ans = 0;
	for(int i=1;i<=n;i++)
		ans = max(ans,dp[i]+up[i]);
	lldout(ans);
	return 0;
}