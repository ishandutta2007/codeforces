#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define pb push_back

const int MAXN = 200010, LOG=18;

int n, q, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN*4], N;
int stt[MAXN], fnt[MAXN], timer=1;
int par[LOG][MAXN], h[MAXN];
int Q[MAXN], V[MAXN], S[MAXN];
int dist[MAXN], dist2[MAXN];
bool mark[MAXN];
int color[MAXN];
vector<int> G[MAXN];
vector<pii> G2[MAXN];
priority_queue<piii, vector<piii>, greater<piii>> pq;

void dfs1(int node){
	stt[node]=timer++;
	for (int i=1; i<LOG; i++) par[i][node]=par[i-1][par[i-1][node]];
	for (int v:G[node]) if (v!=par[0][node]){
		par[0][v]=node;
		h[v]=h[node]+1;
		dfs1(v);
	}
	fnt[node]=timer;
}

inline bool is_par(int x, int y){
	return stt[x]<=stt[y] && fnt[y]<=fnt[x];
}

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[i][y];
	if (x==y) return x;
	for (int i=LOG-1; ~i; i--) if (par[i][x]!=par[i][y]) x=par[i][x], y=par[i][y];
	return par[0][x];
}

void Solve(){
	N=0;
	cin>>k>>m;
	for (int i=1; i<=k; i++){
		cin>>V[i]>>S[i];
		A[N++]=V[i];
	}
	for (int i=1; i<=m; i++){
		cin>>Q[i];
		A[N++]=Q[i];
	}
	
	sort(A, A+N, [](int i, int j){
		return stt[i]<stt[j];
	});
	N=unique(A, A+N)-A;
	int tmp=N;
	for (int i=0; i+1<tmp; i++) A[N++]=Lca(A[i], A[i+1]);
	
	sort(A, A+N, [](int i, int j){
		return stt[i]<stt[j];
	});
	N=unique(A, A+N)-A;
	
	for (int i=0; i<N; i++) G2[A[i]].clear(), dist[A[i]]=dist2[A[i]]=1e9, mark[A[i]]=color[A[i]]=0;
	
	stack<int> stk;
	for (int i=0; i<N; i++){
		int v=A[i];
		while (stk.size() && !is_par(stk.top(), v)) stk.pop();
		if (stk.size()){
			int u=stk.top(), d=h[v]-h[u];
			G2[u].pb({v, d});
			G2[v].pb({u, d});
		}
		stk.push(v);
	}
	
	for (int i=1; i<=k; i++) pq.push({{dist[V[i]]=dist2[V[i]]=0, color[V[i]]=i}, V[i]});
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (pii p:G2[v]){
			int u=p.first, w=p.second, tmp=(dist2[v]+w+S[color[v]]-1)/S[color[v]];
			if (pii(tmp, color[v])<pii(dist[u], color[u])){
				pq.push({{dist[u]=tmp, color[u]=color[v]}, u});
				dist2[u]=dist2[v]+w;
			}
		}
	}
	for (int i=1; i<=m; i++) cout<<color[Q[i]]<<' ';cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1);
	
	cin>>q;
	while (q--) Solve();
	
	return 0;
}