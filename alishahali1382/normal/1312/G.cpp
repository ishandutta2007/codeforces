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
const int MAXN = 1000010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int TR[MAXN][SGM];
int stt[MAXN], fnt[MAXN], timer=1;
int sum[MAXN], V[MAXN];
int dist[MAXN*2], N;
bool mark[MAXN*2];
vector<pii> G[MAXN*2];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void addedge(int u, int v, int w){
	G[u].pb({v, w});
}

void dfs(int node){
	V[node]=++N;
	addedge(node, V[node], 1);
	if (sum[node]) addedge(V[node], node, 0);
	stt[node]=timer++;
	for (int i=0; i<SGM; i++) if (TR[node][i]){
		int v=TR[node][i];
		addedge(node, v, 1);
		dfs(v);
		addedge(V[node], V[v], sum[node]);
		sum[node]+=sum[v];
	}
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		char ch;
		cin>>x>>ch;
		TR[x][ch-'a']=i;
	}
	cin>>k;
	for (int i=1; i<=k; i++) cin>>A[i], sum[A[i]]++;
	N=n;
	dfs(0);
	
	memset(dist, 63, sizeof(dist));
	pq.push({dist[0]=0, 0});
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (pii p:G[v]) if (dist[v]+p.second<dist[p.first]) pq.push({dist[p.first]=dist[v]+p.second, p.first});
	}
	
	for (int i=1; i<=k; i++) cout<<dist[A[i]]<<' ';cout<<'\n';
	
	
	return 0;
}