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
const int MAXN=100005;

int n;ll k;
vector<int> G[MAXN],vc[MAXN];
unordered_set<int> son[MAXN];
int size[MAXN],weight[MAXN],root,dep[MAXN],pa[MAXN];
priority_queue<pii,vector<pii>,less<pii> > q[MAXN],pq;
bool vis[MAXN];
int whi[MAXN];
void dfs1(int u,int pa)
{
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs1(v,u);
		size[u]+=size[v];
		chkmax(weight[u],size[v]);
	}
	chkmax(weight[u],n-size[u]);
}
void dfs2(int u,int f)
{
	whi[u]=f;
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa[u])continue;
		pa[v]=u;
		dep[v]=dep[u]+1;
		dfs2(v,f?f:v);
		son[u].insert(v);
		size[u]+=size[v];
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k);
	for(int i=1;i<n;++i)
	{
		int u,v;
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,-1);
	ll mn=0,mx=0;
	weight[0]=1<<30;
	for(int i=1;i<=n;++i)
	{
		if(weight[i]<=weight[root])root=i;
		mn+=size[i]&1,mx+=min(size[i],n-size[i]);
	}
	if((mn&1)!=(k&1) || k<mn || k>mx)return 0*printf("NO\n");
	printf("YES\n");
	k=(mx-k)/2;
	dfs2(root,0);
	for(int i=1;i<=n;++i)if(!son[i].empty())q[whi[i]].push(mp(dep[i],i));
	for(auto v:G[root])if(size[v]>=2)pq.push(mp(size[v],v));
	size[0]=1;
	while(k)
	{
		int w=pq.top().y;pq.pop();
		pii p=q[w].top();q[w].pop();
		if(p.x>k)break;
		int u=p.y;
		if(son[u].empty())
		{
			if(size[w]>=2)pq.push(mp(size[w],w));
			continue;
		}
		k-=dep[u];
		if(son[u].size()>=2)
		{
			int x=*son[u].begin();son[u].erase(x);
			int y=*son[u].begin();son[u].erase(y);
			printf("%d %d\n",x,y);
			vis[x]=vis[y]=1;
		}
		else
		{
			int x=*son[u].begin();son[u].erase(x);
			son[pa[u]].erase(u);
			printf("%d %d\n",u,x);
			vis[u]=vis[x]=1;
		}
		if(!son[u].empty())q[w].push(mp(dep[u],u));
		size[w]-=2;
		if(size[w]>=2)pq.push(mp(size[w],w));
	}
	int best=1;
	for(auto v:G[root])chkmax(best,size[v]);
	for(int i=1;i<=n;++i)
		if(!vis[i] && dep[i]==k && !son[i].empty() && size[whi[i]]==best)
		{
			int x=*son[i].begin();son[i].erase(x);
			printf("%d %d\n",i,x);
			vis[i]=vis[x]=1;
			size[whi[i]]--,size[whi[x]]--;
			break;
		}
	
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i)if(!vis[i])vc[whi[i]].pb(i);
	for(int i=0;i<=n;++i)if(!vc[i].empty())pq.push(mp(vc[i].size(),i));
	while(!pq.empty())
	{
		int u=pq.top().y;pq.pop();
		int v=pq.top().y;pq.pop();
		printf("%d %d\n",vc[u].back(),vc[v].back());
		vc[u].pop_back(),vc[v].pop_back();
		if(!vc[u].empty())pq.push(mp(vc[u].size(),u));
		if(!vc[v].empty())pq.push(mp(vc[v].size(),v));
	}
	return 0;
}