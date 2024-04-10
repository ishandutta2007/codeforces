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
const int MAXN = 100010, Z=3;

ll n, m, k, u, v, w, s, x, y, t, l, r, ans;
ll dist[MAXN*Z];
bool mark[MAXN*Z];
int seg[MAXN<<2][2], N;
vector<pii> G[MAXN*Z];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void add_edge(int u, int v, int w=0){
	G[u].pb({v, w});
}

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id][0]=seg[id][1]=tl;
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id][0]=++N;
	add_edge(seg[id][0], seg[id<<1][0]);
	add_edge(seg[id][0], seg[id<<1 | 1][0]);
	seg[id][1]=++N;
	add_edge(seg[id<<1][1], seg[id][1]);
	add_edge(seg[id<<1 | 1][1], seg[id][1]);
}

void Add(int id, int tl, int tr, int l, int r, int v, int w, int typ){
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		if (typ) add_edge(seg[id][1], v, w);
		else add_edge(v, seg[id][0], w);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, v, w, typ);
	Add(id<<1 | 1, mid, tr, l, r, v, w, typ);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>n>>m>>s;
	N=n;
	Build(1, 1, n+1);
	while (m--){
		cin>>t>>v;
		if (t==1){
			cin>>u>>w;
			add_edge(v, u, w);
			continue ;
		}
		cin>>l>>r>>w;
		Add(1, 1, n+1, l, r+1, v, w, t-2);
	}
	
	pq.push({dist[s]=0, s});
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (pii p:G[v]) if (dist[p.first]>dist[v]+p.second) pq.push({dist[p.first]=dist[v]+p.second, p.first});
	}
	
	for (int i=1; i<=n; i++){
		if (dist[i]>=INF) dist[i]=-1;
		cout<<dist[i]<<" \n"[i==n];
	}
	
	return 0;
}