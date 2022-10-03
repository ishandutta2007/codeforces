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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, SHIT=10000000, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN][LOG], H[MAXN], sum[MAXN];
int seg[MAXN<<2], N;
bool mark[SHIT];
int comp[SHIT];
set<int> st[MAXN];
vector<int> T[MAXN], vec1[MAXN], vec2[MAXN];
vector<int> G[SHIT], GR[SHIT], topol;

void dfs1(int node){
	H[node]=H[par[node][0]]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:T[node]) if (v!=par[node][0]){
		par[v][0]=node;
		dfs1(v);
	}
}

int Lca(int x, int y){
	if (H[x]>H[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((H[y]-H[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; ~i; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	return par[x][0];
}

int dfs2(int node){
	for (int v:T[node]) if (v!=par[node][0]) sum[node]+=dfs2(v);
	return sum[node];
}

inline void add_edge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
}
inline void add_clause(int u, int v){
	//debug2(u, v)
	add_edge(u^1, v);
	add_edge(v^1, u);
}

void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	
	if (seg[id<<1]!=-1 && seg[id<<1 | 1]!=-1){
		seg[id]=((N++)<<1);
		add_clause(seg[id<<1] ^ 1, seg[id]);
		add_clause(seg[id<<1 | 1] ^ 1, seg[id]);
		add_clause(seg[id<<1] ^ 1, seg[id<<1 | 1] ^ 1);
	}
	else seg[id]=seg[id<<1] + seg[id<<1 | 1] + 1;
}

inline void Add(int x){
	//cerr<<"Add "<<x<<endl;
	Set(1, 0, m<<1, x, x);
}
inline void Rem(int x){
	//cerr<<"Rem "<<x<<endl;
	Set(1, 0, m<<1, x, -1);
}

inline bool is_in(vector<int> &vec, int x){
	auto it=lower_bound(all(vec), x);
	return (it!=vec.end() && *it==x);
}

void dfs3(int node){
	int big=0;
	for (int v:T[node]) if (v!=par[node][0] && sum[v]>sum[big]) big=v;
	for (int v:T[node]) if (v!=par[node][0] && v!=big){
		dfs3(v);
		for (int x:st[v]) Rem(x);
	}
	if (big){
		dfs3(big);
		st[big].swap(st[node]);
	}
	for (int x:vec2[node]) if (st[node].count(x)){
		st[node].erase(x);
		Rem(x);
	}
	for (int v:T[node]) if (v!=par[node][0] && v!=big){
		for (int x:st[v]) if (!is_in(vec2[node], x)) Add(x), st[node].insert(x);
		st[v].clear();
	}
	for (int x:vec1[node]) if (!is_in(vec2[node], x)) Add(x), st[node].insert(x);
	/*
	debug(node)
	debugv(st[node])
	cerr<<'\n';
	*/
}

void dfs4(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs4(v);
	topol.pb(node);
}

void dfs5(int node, int cid){
	comp[node]=cid;
	for (int v:GR[node]) if (!comp[v]) dfs5(v, cid);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		T[u].pb(v);
		T[v].pb(u);
	}
	dfs1(1);
	
	cin>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v>>x>>y;
		int lca=Lca(u, v);
		vec1[u].pb(i<<1 | 1);
		vec1[v].pb(i<<1 | 1);
		vec2[lca].pb(i<<1 | 1);
		sum[u]++;
		sum[v]++;
		sum[lca]-=2;
		
		lca=Lca(x, y);
		vec1[x].pb(i<<1);
		vec1[y].pb(i<<1);
		vec2[lca].pb(i<<1);
		sum[x]++;
		sum[y]++;
		sum[lca]-=2;
	}
	dfs2(1);
	memset(seg, -1, sizeof(seg));
	N=m;
	for (int i=1; i<=n; i++) sort(all(vec2[i]));
	dfs3(1);
	
	for (int i=0; i<2*N; i++) if (!mark[i]) dfs4(i);
	reverse(all(topol));
	//debugv(topol)
	int cid=1;
	for (int v:topol) if (!comp[v]) dfs5(v, cid++);
	
	//for (int i=0; i<2*N; i++) debug2(i, comp[i])
	
	for (int i=0; i<N; i++) if (comp[i<<1]==comp[i<<1 | 1]) kill("NO")
	
	cout<<"YES\n";
	for (int i=0; i<m; i++) cout<<(comp[i<<1]>comp[i<<1 | 1])+1<<'\n';
	
	return 0;
}