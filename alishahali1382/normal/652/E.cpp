#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

struct DSU{
	int par[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		par[get(x)]=get(y);
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans;
int E[MAXN][3];
bool cut[MAXN];
int h[MAXN];
bool good[MAXN];
vector<pii> G[MAXN];
vector<int> path;

int bridge(int node, int par, int parid){
	int res=h[node]=h[par]+1;
	for (pii p:G[node]) if (p.first!=par){
		if (!h[p.first]) res=min(res, bridge(p.first, node, p.second));
		else res=min(res, h[p.first]);
	}
	if (res==h[node]) cut[parid]=1;
	return res;
}

bool dfs(int node, int par){
	if (node==b) return 1;
	for (pii p:G[node]) if (p.first!=par){
		path.pb(p.second|good[p.first]);
		if (dfs(p.first, node)) return 1;
		path.pop_back();
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>E[i][2];
		E[i][0]=u;
		E[i][1]=v;
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	bridge(1, 0, 0);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<=m; i++) if (!cut[i]) dsu.join(E[i][0], E[i][1]);
	for (int i=1; i<=m; i++){
		if (cut[i]){
			int u=dsu.get(E[i][0]), v=dsu.get(E[i][1]), w=E[i][2];
			G[u].pb({v, w});
			G[v].pb({u, w});
			//debug2(u, v)
		}
		else if (E[i][2]) good[dsu.get(E[i][0])]=1/*, debug("shit")*/;
	}
	cin>>a>>b;
	a=dsu.get(a);
	b=dsu.get(b);
	path.pb(good[a]);
	dfs(a, a);
	//debugv(path)
	for (int x:path) ans|=x;
	if (ans) kill("YES")
	kill("NO")
	
	return 0;
}