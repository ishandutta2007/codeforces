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
const int MAXN = 200010, LOG=19;

int n, m, q, u, v, x, y, t, a, b;
int par[MAXN][LOG];
int h[MAXN];
int up[MAXN][LOG];
int stt[MAXN], fnt[MAXN], timer=1;
int ans[MAXN];
int B[MAXN];
set<pii> fen[MAXN];
vector<int> G[MAXN], V[MAXN];
vector<pii> Q[MAXN];

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	return par[x][0];
}

void dfs1(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs1(v);
	fnt[node]=timer;
}

inline bool is_par(int u, int v){
	return stt[u]<=stt[v] && fnt[v]<=fnt[u];
}

inline void add(int pos, pii p){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos].insert(p);
}
inline void rem(int pos, pii p){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos].erase(p);
}

inline pii get(int pos){
	pii res={0, 0};
	for (; pos; pos-=pos&-pos) if (fen[pos].size()) res=max(res, *fen[pos].rbegin());
	return res;
}

void dfs2(int node){
	for (pii p:Q[node]) add(stt[p.first], {fnt[p.first], p.second});
	for (int v:V[node]){
		int l=stt[v], r=fnt[v];
		while (1){
			pii p=get(l);
			if (p.first<r) break ;
			int i=p.second;
			ans[i]--;
			rem(stt[B[i]], {fnt[B[i]], i});
		}
	}
	for (int v:G[node]) dfs2(v);
	for (pii p:Q[node]) rem(stt[p.first], {fnt[p.first], p.second});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n; i++){
		cin>>par[i][0];
		G[par[i][0]].pb(i);
		h[i]=h[par[i][0]]+1;
		for (int j=1; j<LOG; j++) par[i][j]=par[par[i][j-1]][j-1];
	}
	for (int i=1; i<=n; i++) up[i][0]=i;
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>a>>b;
		int lca=Lca(a, b);
		up[a][0]=min(up[a][0], lca);
		up[b][0]=min(up[b][0], lca);
		V[a].pb(b);
		V[b].pb(a);
	}
	for (int i=n; i; i--) if (up[i][0]!=i) up[par[i][0]][0]=min(up[par[i][0]][0], up[i][0]);
	for (int i=1; i<=n; i++) for (int j=1; j<LOG; j++) up[i][j]=up[up[i][j-1]][j-1];
	dfs1(1);
	
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>a>>b;
		if (up[a][LOG-1]!=up[b][LOG-1]) ans[i]=-1;
		else{
			int lca=Lca(a, b);
			ans[i]+=(a!=lca)+(b!=lca);
			for (int j=LOG-1; j>=0; j--) if (!is_par(up[a][j], lca)) a=up[a][j], ans[i]+=(1<<j);
			for (int j=LOG-1; j>=0; j--) if (!is_par(up[b][j], lca)) b=up[b][j], ans[i]+=(1<<j);
			if (min(a, b)!=lca) Q[a].pb({b, i});
			B[i]=b;
		}
	}
	dfs2(1);
	
	for (int i=1; i<=q; i++) cout<<ans[i]<<'\n';
	
	return 0;
}