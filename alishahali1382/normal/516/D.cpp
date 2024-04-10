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

ll n, m, k, u, v, x, y, t, l, root;
ll D[MAXN], dist[MAXN];
int stt[MAXN], fnt[MAXN], timer=1, pos[MAXN];
int ans[MAXN];
vector<pii> G[MAXN];
vector<pll> vec; 

void dfs1(int node, int par){
	for (pii p:G[node]) if (p.first!=par){
		dist[p.first]=dist[node]+p.second;
		dfs1(p.first, node);
	}
}

void dfs2(int node, int par){
	pos[timer]=node;
	stt[node]=timer++;
	for (pii p:G[node]) if (p.first!=par) dfs2(p.first, node);
	fnt[node]=timer;
}

int dfs3(int node, int par){
	vec.pb({D[node], node});
	ans[node]++;
	ans[(lower_bound(all(vec), pll(D[node]-l, 0))-1)->second]--;
	for (pii p:G[node]) if (p.first!=par) dfs3(p.first, node);
	vec.pop_back();
}

int dfs4(int node, int par){
	for (pii p:G[node]) if (p.first!=par) ans[node]+=dfs4(p.first, node);
	return ans[node];
}

void solve(){
	cin>>l;
	memset(ans, 0, sizeof(ans));
	dfs3(root, 0);
	dfs4(root, 0);
	cout<<(*max_element(ans+1, ans+n+1))<<'\n';
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
	dfs1(1, 0);
	root=max_element(dist+1, dist+n+1)-dist;
	dist[root]=0;
	dfs1(root, 0);
	memcpy(D, dist, sizeof(D));
	root=max_element(dist+1, dist+n+1)-dist;
	dist[root]=0;
	dfs1(root, 0);
	for (int i=1; i<=n; i++) D[i]=max(D[i], dist[i]);
	root=min_element(D+1, D+n+1)-D;
	dfs2(root, 0);
	
	vec.pb({-INF, 0});
	cin>>m;
	while (m--) solve();
	
	return 0;
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
1
2



*/