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
const int mod = 1000000007;
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN];
int comp[MAXN];
vector<int> G[MAXN], GR[MAXN], topol;

void addedge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
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

int solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) mark[i]=comp[i]=0, G[i].clear(), GR[i].clear();
	while (m--){
		cin>>u>>v;
		addedge(u, v);
	}
	topol.clear();
	for (int i=1; i<=n; i++) if (!mark[i]) dfs1(i);
	reverse(all(topol));
	int scc, cnt=0;
	for (int v:topol) if (!comp[v]) dfs2(v, v), cnt++, scc=v;
	
	if (cnt==1) kill("No")
	cnt=0;
	for (int i=1; i<=n; i++) cnt+=(comp[i]==scc);
	cout<<"Yes\n";
	cout<<cnt<<' '<<n-cnt<<'\n';
	for (int i=1; i<=n; i++) if (comp[i]==scc) cout<<i<<' ';cout<<'\n';
	for (int i=1; i<=n; i++) if (comp[i]!=scc) cout<<i<<' ';cout<<'\n';
	 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}