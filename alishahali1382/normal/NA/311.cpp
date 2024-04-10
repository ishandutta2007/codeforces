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

int n, m, k, u, v, x, y, t, a, b, ans, sz;
int stt[MAXN], fnt[MAXN], timer=1, pos[MAXN];
int par[MAXN][LOG];
int h[MAXN];
vector<int> G[MAXN];
set<int> st;

void dfs(int node, int p){
	h[node]=h[par[node][0]=p]+1;
	pos[stt[node]=timer++]=node;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=p) dfs(v, node);
	fnt[node]=timer;
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

int dist(int u, int v){
	return h[u]+h[v]-2*h[LCA(u, v)];
}

int prv(int x){
	auto it=st.lower_bound(stt[x]);
	if (it==st.begin()) return pos[*st.rbegin()];
	return pos[*--it];
}

int nxt(int x){
	auto it=++st.lower_bound(stt[x]);
	if (it==st.end()) return pos[*st.begin()];
	return pos[*it];
}

void Add(int x){
	st.insert(stt[x]);
	int u=prv(x), v=nxt(x);
	sz+=dist(u, x)+dist(x, v)-dist(u, v);
	//cerr<<"Add "<<x<<"  sz="<<sz<<'\n';
	//debug2(u, v)
	//cerr<<'\n';
}

void Rem(int x){
	int u=prv(x), v=nxt(x);
	sz-=dist(u, x)+dist(x, v)-dist(u, v);
	st.erase(stt[x]);
	//cerr<<"Rem "<<x<<"  sz="<<sz<<'\n';
	//debug2(u, v)
	//cerr<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	k=2*k-2;
	int j=1;
	for (int i=1; i<=n; i++){
		while (sz<=k && j<=n){
			ans=max(ans, j-i);
			//debug2(i, j)
			Add(j++);
		}
		if (sz<=k) ans=max(ans, j-i);
		Rem(i);
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*
5 3
1 2
1 5
4 5
3 5
*/