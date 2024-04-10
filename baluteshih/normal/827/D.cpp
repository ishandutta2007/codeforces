#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	int a,b,w,i;
	bool operator<(const mode &x)const{
		return w<x.w;
	}
}edge[200005];

const int INF=2e9;

struct node
{
	int pa,mx,lazy;
	node(){}
	node(int pa,int mx):pa(pa),mx(mx),lazy(INF){}
	node operator+(const node &x)const{
		return node(x.pa,max(mx,x.mx));
	}
}dp[18][200005];

vector<int> G[200005];
int boss[200005],ans[200005],pe[200005],L,t,in[200005],out[200005];
bitset<200005> vis;

int finds(int x)
{
	if(boss[x]==x) return x;
	return boss[x]=finds(boss[x]);
}

void Union(int a,int b,int i)
{
	if(finds(a)==finds(b)) return;
	G[a].pb(i),G[b].pb(i),boss[finds(a)]=finds(b),vis[i]=1;
}

void dfs(int u,int f)
{
	in[u]=++t;
	for(int i=1;i<=L;++i)
		dp[i][u]=dp[i-1][u]+dp[i-1][dp[i-1][u].pa];
	for(int i:G[u])
		if((edge[i].a^edge[i].b^u)!=f)
			pe[edge[i].a^edge[i].b^u]=edge[i].i,dp[0][edge[i].a^edge[i].b^u]=node(u,edge[i].w),dfs(edge[i].a^edge[i].b^u,u);
	out[u]=t;
}

bool ancestor(int a,int b)
{
	return in[a]<=in[b] && out[a]>=out[b];
}

int LCA(int a,int b,int w)
{
	if(ancestor(a,b)) return 0;
	int re=0;
	for(int i=L;i>=0;--i)
		if(!ancestor(dp[i][a].pa,b)) dp[i][a].lazy=min(dp[i][a].lazy,w),re=max(re,dp[i][a].mx),a=dp[i][a].pa;
	dp[0][a].lazy=min(dp[0][a].lazy,w);
	return max(re,dp[0][a].mx);
}

int main()
{jizz
	int n,m;
	cin >> n >> m,L=__lg(n);
	for(int i=0;i<m;++i)
		cin >> edge[i].a >> edge[i].b >> edge[i].w,edge[i].i=i;
	for(int i=1;i<=n;++i) boss[i]=i;
	sort(edge,edge+m);
	for(int i=0;i<m;++i)
		Union(edge[i].a,edge[i].b,i);
	dp[0][1]=node(1,0),dfs(1,1);
	for(int i=0;i<m;++i)
		if(!vis[i])
		{
			int tmp=max(LCA(edge[i].a,edge[i].b,edge[i].w),LCA(edge[i].b,edge[i].a,edge[i].w));
			ans[edge[i].i]=tmp-1;
		}
	for(int i=L;i>0;--i)
		for(int j=1;j<=n;++j)
			dp[i-1][j].lazy=min(dp[i][j].lazy,dp[i-1][j].lazy),dp[i-1][dp[i-1][j].pa].lazy=min(dp[i][j].lazy,dp[i-1][dp[i-1][j].pa].lazy);
	for(int i=2;i<=n;++i)
		if(dp[0][i].lazy==INF) ans[pe[i]]=-1;
		else ans[pe[i]]=dp[0][i].lazy-1;
	for(int i=0;i<m;++i)
		cout << ans[i] << " \n"[i==m-1]; 
}