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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int dist[MAXN], N, M;
bool mark[MAXN];
int ans[MAXN];
vector<int> G[MAXN][10];
vector<int> vec[MAXN*2];
queue<int> Q;

void add_edge(int u, int v, int w){
	vector<int> tmp;
	while (w) tmp.pb(w%10), w/=10;
	reverse(all(tmp));
	for (int i=0; i<tmp.size()-1; i++){
		G[u][tmp[i]].pb(++N);
		u=N;
	}
	G[u][tmp.back()].pb(v);
}

void dfs(int id){
	if (vec[id].empty()) return ;
	//debugv(vec[id])
	for (int node:vec[id]) mark[node]=1;
	ll cur=ans[vec[id].back()];
	//debug(cur)
	for (int w=0; w<10; w++){
		M++;
		for (int node:vec[id]){
			for (int v:G[node][w]) if (dist[node]+1==dist[v] && !mark[v]) vec[M].pb(v);
			G[node][w].clear();
			G[node][w].shrink_to_fit();
		}
		for (int v:vec[M]) ans[v]=(cur*10+w)%mod;
		
		if (vec[M].size()) dfs(M);
		else M--;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	N=n;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		add_edge(u, v, i);
		add_edge(v, u, i);
	}
	memset(dist, 63, sizeof(dist));
	dist[1]=0;
	Q.push(1);
	while (!Q.empty()){
		int v=Q.front();
		Q.pop();
		for (int tmp=0; tmp<10; tmp++) for (int x:G[v][tmp]) if (dist[v]+1<dist[x]){
			dist[x]=dist[v]+1;
			Q.push(x);
		}
	}
	//for (int i=1; i<=N; i++) level[dist[i]].pb(i);
	vec[M].pb(1);
	dfs(M);
	for (int i=2; i<=n; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
4 10
1 2
2 3
1 4
1 4
1 4
1 4
1 4
1 4
1 4
1 3
*/