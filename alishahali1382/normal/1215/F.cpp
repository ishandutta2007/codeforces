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
const int MAXN = 800010, LOG=20;

int n, p, M, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN*2];
int comp[MAXN*2], id=1;
int L[MAXN], R[MAXN];
vector<int> G[MAXN*2], GR[MAXN*2];
vector<int> topol;

void add_edge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
}

void add_clause(int u, int v){
	add_edge(u^1, v);
	add_edge(v^1, u);
}

void dfs1(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs1(v);
	topol.pb(node);
}

void dfs2(int node, int cid){
	comp[node]=cid;
	for (int v:GR[node]) if (!comp[v]) dfs2(v, cid);
}

void SCC(){
	for (int i=0; i<MAXN*2; i++) if (!mark[i]) dfs1(i);
	reverse(all(topol));
	for (int v:topol) if (!comp[v]) dfs2(v, id++);
}

bool SAT(){
	SCC();
	for (int i=0; i<MAXN; i+=2) if (comp[i]==comp[i^1]) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p>>M>>m;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		add_clause(2*x, 2*y);
	}
	for (int i=1; i<=p; i++){
		cin>>L[i]>>R[i];
		add_clause(2*i+1, 2*(R[i]+p+1));
		add_clause(2*(p+L[i])+1, i*2+1);
	}
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		add_clause(2*x+1, 2*y+1);
	}
	for (int i=1; i<=M; i++) add_clause(2*(p+i)+1, 2*(p+i+1));
	if (!SAT()) kill(-1)
	vector<int> out;
	for (int i=1; i<=p; i++) if (comp[2*i]>comp[2*i+1]) out.pb(i);
	int l=1, r=M;
	for (int i:out){
		l=max(l, L[i]);
		r=min(r, R[i]);
	}
	cout<<out.size()<<' '<<l<<'\n';
	for (int i:out) cout<<i<<' ';
	
	return 0;
}