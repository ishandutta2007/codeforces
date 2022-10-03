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
const int MAXN = 100010, LOG=17;

ll n, m, k, u, v, x, y, t, a, b, ans;
int stt[MAXN], pos[MAXN], timer=1;
int par[MAXN][LOG];
int h[MAXN];
ll H[MAXN];
vector<pii> G[MAXN];
set<int> st;

void dfs(int node, int p){
	pos[stt[node]=timer++]=node;
	h[node]=h[par[node][0]=p]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (pii pp:G[node]) if (pp.first!=p){
		H[pp.first]=H[node]+pp.second;
		dfs(pp.first, node);
	}
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

ll dist(int u, int v){
	return H[u]+H[v]-2*H[LCA(u, v)];
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
	ans+=dist(u, x)+dist(x, v)-dist(u, v);
}

void Rem(int x){
	int u=prv(x), v=nxt(x);
	ans-=dist(u, x)+dist(x, v)-dist(u, v);
	st.erase(stt[x]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	dfs(1, 1);
	
	char ch;
	cin>>m;
	while (m--){
		cin>>ch;
		if (ch=='?') cout<<(ans/2)<<'\n';
		else{
			cin>>v;
			if (ch=='+') Add(v);
			else Rem(v);
		}
	}
	
	return 0;
}
/*
6
1 2 1
1 3 5
4 1 7
4 5 3
6 4 2
4
+ 3
+ 1
+ 6
?

*/