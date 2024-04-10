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
const int N = int(2e5);
set<int> g[N];
int dp[2][N],top[2][N],cnt[N],root,par[N];
II ans;
void fucktree(int u,int p)
{
	VI fuck;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			fucktree(*it,u);
			if(!cnt[*it])fuck.PB(*it);
			cnt[u]+=cnt[*it];
		}
	for(int i=0;i<SZ(fuck);i++)
		g[u].erase(fuck[i]);
}
//dp[0][i] = ans to explore subtree i and return back to node i
//dp[1][i] = ans to explore subtree i and do not return to node i
//top[0][i] = ans to explore the top and return to top
//top[1][i] = ans to explore the top and do not return to top
void dfs(int u,int p)
{
	par[u]=p;
	for(auto it = g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs(*it,u);
			dp[0][u]+=dp[0][*it]+2;
		}
	dp[1][u] = dp[0][u];
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
			dp[1][u] = min(dp[1][u],dp[0][u]-dp[0][*it]+dp[1][*it]-1);
}
void dfs2(int u,int p)
{
	if(u!=root)
	{
		top[0][u] = top[0][p] + dp[0][p] - dp[0][u] - (p==root?2:0);
		top[1][u] = top[0][u] - top[0][p] + top[1][p] - (p==root?0:1);
		for(auto it = g[p].begin();it!=g[p].end();it++)
		{
			if(*it==par[p])continue;
			if(*it==u)continue;
			top[1][u]=min(top[1][u],top[0][u]-1-dp[0][*it]+dp[1][*it]);
		}
		ans = min(ans,{top[0][u]+2+dp[1][u],u});
		ans = min(ans,{dp[0][u]+1+top[1][u],u});
	}
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
			dfs2(*it,u);
}
int main()
{
	int n;si(n);
	int m;si(m);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		si(u);si(v);
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=0;i<m;i++)
	{
		int x;si(x);
		cnt[x]++;
		root=x;
	}
	fucktree(root,root);
	dfs(root,root);
	ans = {dp[1][root],root};
	dfs2(root,root);
	dout(ans.S);
	dout(ans.F);
	return 0;
}