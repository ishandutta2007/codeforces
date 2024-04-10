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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int dist[MAXN];
int dist2[MAXN];
int par[MAXN];
bool mark[MAXN];
char parc[MAXN];
vector<int> G[MAXN][10];
vector<int> shit[MAXN];
queue<int> Q;
queue<vector<int>> Q2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	memset(dist2, 63, sizeof(dist2));
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u][x].pb(v);
		G[v][x].pb(u);
	}
	
	dist2[n-1]=0;
	Q.push(n-1);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		//debug(v)
		dist[v]=0;
		for (int u:G[v][0]) if (dist2[v]+1<dist2[u]){
			dist2[u]=dist2[v]+1;
			par[u]=v;
			Q.push(u);
		}
	}
	
	for (int i=0; i<n; i++) if (!dist[i]) Q.push(i);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		for (int len=0; len<10; len++) for (int u:G[v][len]) if (dist[v]+1<dist[u]){
			dist[u]=dist[v]+1;
			Q.push(u);
		}
	}
	
	vector<int> vec;
	for (int i=0; i<n; i++) if (!dist[i]) shit[dist2[i]].pb(i);
	for (int i=0; i<MAXN; i++) for (int v:shit[i]) vec.pb(v);
	Q2.push(vec);
	while (Q2.size()){
		vector<int> vec=Q2.front();
		Q2.pop();
		if (vec.empty()) continue ;
		//debugv(vec)
		for (int len=0; len<10; len++){
			vector<int> tmp;
			for (int v:vec) for (int u:G[v][len]) if (dist[v]+1==dist[u] && !mark[u]){
				tmp.pb(u);
				mark[u]=1;
				//cerr<<"par["<<u<<"]="<<v<<"   ";
				//debug((char)('0'+len))
				par[u]=v;
				parc[u]='0'+len;
			}
			if (tmp.empty()) continue ;
			Q2.push(tmp);
		}
	}
	
	string ans;
	vector<int> path;
	for (int v=0; v!=n-1; v=par[v]){
		path.pb(v);
		if (parc[v]) ans+=parc[v];
	}
	path.pb(n-1);
	reverse(all(ans));
	if (ans.empty()) ans="0";
	
	cout<<ans<<'\n';
	cout<<path.size()<<'\n';
	for (int i:path) cout<<i<<' ';
	
	
	return 0;
}
/*
11 11
0 1 1
1 2 0
2 3 0
3 4 0
4 5 0
10 5 0
6 5 0
6 7 0
7 8 0
9 8 0
1 9 0


100 11
0 4 9
0 97 9
4 5 0
5 6 0
6 7 0
7 8 0
8 9 0
9 10 0
10 99 0
0 98 9
98 99 0



*/