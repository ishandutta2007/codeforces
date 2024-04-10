#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

const int inf=1000000010;
const int MAXN = 200010;

struct edge{
	int u, v, c, t, res;
} E[MAXN];

int n, m, k, u, v, x, y, t, a, b, N;
int comp[MAXN*2];
bool mark[MAXN*2];
int del[MAXN*2];
int del2[MAXN*2];
map<int, int> deg[MAXN];
map<int, vector<int>> GRAPH[MAXN];
vector<int> GRAPH2[MAXN];
vector<int> G[2*MAXN];
vector<int> GR[2*MAXN];
vector<int> topol;

void add_edge(int x, int y){
	G[x].pb(y);
	GR[y].pb(x);
}

void add(int x, int y){
	add_edge(x^1, y);
	add_edge(y^1, x);
}

void add2(int x, int y){
	add_edge(x^1, y);
	add_edge(y^1, x);
	del[x^1]++;
	del[y^1]++;
	del2[y]++;
	del2[x]++;
}

void dfs1(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs1(v);
	topol.pb(node);
}

void dfs2(int node, int id){
	comp[node]=id;
	for (int v:GR[node]) if (!comp[v]) dfs2(v, id);
}

bool check(int T){
	for (int i=0; i<2*MAXN; i++){
		while (del[i]){
			G[i].pop_back();
			del[i]--;
		}
		while (del2[i]){
			GR[i].pop_back();
			del2[i]--;
		}
	}
	for (int i=1; i<=m; i++) if (E[i].t>T) add2(2*i^1, 2*i^1);
	memset(comp, 0, sizeof(comp));
	memset(mark, 0, sizeof(mark));
	topol.clear();
	for (int i=2; i<2*MAXN; i++) if (!mark[i]) dfs1(i);
	reverse(all(topol));
	int id=1;
	for (int v:topol) if (!comp[v]) dfs2(v, id++);
	
	for (int i=2; i<2*N+2; i++) if (comp[i]==comp[i^1]) return 0;
	for (int i=1; i<=m; i++) E[i].res=(comp[2*i]>comp[2*i+1]);
	
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>x>>y;
		E[i]={u, v, x, y};
		deg[u][x]++;
		deg[v][x]++;
		GRAPH[u][x].pb(i);
		GRAPH[v][x].pb(i);
		GRAPH2[u].pb(i);
		GRAPH2[v].pb(i);
	}
	for (int i=1; i<=n; i++) for (pii p:deg[i]) if (p.second>2) kill("No")
	
	for (int i=1; i<=n; i++) for (auto it:GRAPH[i]) if (it.second.size()==2) add(it.second[0]*2, it.second[1]*2);
	
	N=m;
	for (int i=1; i<=n; i++) if (GRAPH2[i].size()>=2){
		k=GRAPH2[i].size();
		for (int j=0; j<k; j++){
			int a=GRAPH2[i][j];
			add(2*a^1, 2*(++N));
			if (j) add(2*(N-1)^1, 2*N);
			if (j) add(2*a^1, 2*(N-1)^1);
		}
	}
	
	int dwn=-1, up=inf;
	while (up-dwn>1){
		int mid=(dwn+up)/2;
		if (check(mid)) up=mid;
		else dwn=mid;
	}
	
	if (!check(up)) kill("No")
	vector<int> out;
	for (int i=1; i<=m; i++) if (E[i].res) out.pb(i);
	cout<<"Yes\n"<<up<<' '<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';cout<<'\n';
	
	return 0;
}