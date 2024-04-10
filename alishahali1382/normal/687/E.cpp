#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN=5010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN];
int comp[MAXN], bad[MAXN], cid;
int cnt[MAXN];
int dist[MAXN][MAXN];
pii E[MAXN];
vector<int> G[MAXN], GR[MAXN], topol;
queue<int> Q;

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
	topol.pb(node);
}
void sfd(int node, int cid){
	comp[node]=cid;
	for (int v:GR[node]) if (!comp[v]) sfd(v, cid);
}

int Solve(int id){
	int ans=n;
	for (int v=1; v<=n; v++) if (comp[v]==id) for (int i=0; i<m; i++)
		ans=min(ans, dist[v][E[i].first]+1+dist[E[i].second][v]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v;
		G[u].pb(v);
		GR[v].pb(u);
		E[i]={u, v};
	}
	for (int v=1; v<=n; v++) if (!mark[v]) dfs(v);
	reverse(all(topol));
	for (int v:topol) if (!comp[v]) sfd(v, ++cid);
	for (int v=1; v<=n; v++){
		cnt[comp[v]]++;
		for (int u:G[v]) if (comp[v]!=comp[u]) bad[comp[v]]=1;
	}
	
	memset(dist, 31, sizeof(dist));
	for (int i=1; i<=n; i++){
		dist[i][i]=0;
		Q.push(i);
		while (Q.size()){
			int v=Q.front();
			Q.pop();
			for (int u:G[v]) if (dist[i][v]+1<dist[i][u]){
				dist[i][u]=dist[i][v]+1;
				Q.push(u);
			}
		}
	}
	for (int i=1; i<=cid; i++) if (!bad[i] && cnt[i]>1) ans+=998*Solve(i)+1;
	cout<<ans+n<<'\n';
	
	return 0;
}