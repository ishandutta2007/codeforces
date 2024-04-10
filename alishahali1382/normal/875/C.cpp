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
#define SZ(x) x.size()

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
bool mark[MAXN<<1];
int comp[MAXN<<1];
bool res[MAXN];
vector<int> G[MAXN<<1], GR[MAXN<<1], topol;
vector<int> A[MAXN], out;

void add_edge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
}

void add_clause(int x, int y){
	add_edge(x^1, y);
	add_edge(y^1, x);
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

bool SAT(){
	for (int i=2; i<2*m+2; i++) if (!mark[i]) dfs1(i);
	reverse(all(topol));
	int N=1;
	for (int v:topol) if (!comp[v]) dfs2(v, N++);
	for (int i=1; i<=m; i++){
		if (comp[i<<1]==comp[i<<1 | 1]) return 0;
		res[i]=(comp[i<<1]>comp[i<<1 | 1]);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>k;
		A[i].resize(k);
		for (int j=0; j<k; j++) cin>>A[i][j];
	}
	for (int i=1; i<n; i++){
		int lcp=0;
		while (lcp<min(SZ(A[i]), SZ(A[i+1])) && A[i][lcp]==A[i+1][lcp]) lcp++;
		if (SZ(A[i])<=SZ(A[i+1]) && SZ(A[i])==lcp) continue ;
		if (SZ(A[i])>SZ(A[i+1]) && SZ(A[i+1])==lcp) kill("No")
		int a=A[i][lcp], b=A[i+1][lcp];
		if (a>b){
			add_clause(a<<1, a<<1);
			add_clause(b<<1 ^ 1, b<<1 ^ 1);
			continue ;
		}
		add_clause(a<<1, b<<1 ^ 1);
	}
	if (!SAT()) kill("No")
	cout<<"Yes\n";
	for (int i=1; i<=m; i++) if (res[i]) out.pb(i);
	cout<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';
	
	
	return 0;
}