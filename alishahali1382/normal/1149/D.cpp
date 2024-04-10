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
const int N=70, M=N/4;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], comp[N], sz[N];
int compp[N], ted;
int dist[N<<M];
bool mark[N<<M];
vector<int> Ga[N], Gb[N];
queue<int> Q;

void dfs(int node, int id){
	sz[comp[node]=id]++;
	for (int v:Ga[node]) if (comp[v]==-1) dfs(v, id);
}

inline void upd(int v, int d){
	if (d<dist[v]){
		dist[v]=d;
		//cerr<<(v>>ted)<<' '<<(v%(1<<ted))<<" : "<<d<<endl;
		if (!mark[v]){
			mark[v]=1;
			Q.push(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>a>>b;
	while (m--){
		cin>>u>>v>>x;
		u--;
		v--;
		if (x==a){
			Ga[u].pb(v);
			Ga[v].pb(u);
		}
		if (x==b){
			Gb[u].pb(v);
			Gb[v].pb(u);
		}
	}
	memset(comp, -1, sizeof(comp));
	memset(compp, -1, sizeof(compp));
	for (int v=0; v<n; v++) if (comp[v]==-1){
		dfs(v, t);
		if (sz[t]>3) compp[t]=ted++;
		t++;
	}
	
	memset(dist, 63, sizeof(dist));
	if (compp[comp[0]]==-1) upd(0, 0);
	else upd(1<<compp[comp[0]], 0);
	while (Q.size()){
		int vt=Q.front();
		Q.pop();
		mark[vt]=0;
		int v=vt>>ted, mask=(vt&((1<<ted)-1));
		for (int u:Ga[v]) upd(u<<ted|mask, dist[vt]+a);
		for (int u:Gb[v]) if (comp[v]!=comp[u]){
			int tmp=compp[comp[u]];
			if (tmp==-1) upd(u<<ted|mask, dist[vt]+b);
			if (tmp!=-1){
				if (mask&(1<<tmp)) continue ;
				upd(u<<ted|mask|(1<<tmp), dist[vt]+b);
			}
		}
	}
	for (int v=0; v<n; v++){
		ans=inf;
		for(int mask=0; mask<(1<<ted); mask++) ans=min(ans, dist[v<<ted|mask]);
		cout<<ans<<' ';
	}
	
	
	return 0;
}