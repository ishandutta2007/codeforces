#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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
const int MAXN = 100010, H=10007;

int n, m, k, u, v, x, y, t, a, b;
int ans[MAXN];
int id[MAXN];
int par[MAXN], sz[MAXN], h[MAXN];
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
unordered_set<int> sack[MAXN];
string name[MAXN];
vector<int> G[MAXN];
vector<pii> query[MAXN];
vector<string> compress;

int dfs1(int node){
	ras[timer]=node;
	stt[node]=timer++;
	h[node]=h[par[node]]+1;
	for (int v:G[node]) sz[node]+=dfs1(v);
	fnt[node]=timer;
	return ++sz[node];
}

void dfs2(int node){
	int big=0;
	for (int v:G[node]) if (!big || sz[v]>sz[big]) big=v;
	for (int v:G[node]) if (v!=big){
		dfs2(v);
		for (int i=h[v]; sack[i].size(); i++) sack[i].clear();
	}
	if (big) dfs2(big);
	for (int v:G[node]) if (v!=big)
		for (int i=stt[v]; i<fnt[v]; i++) sack[h[ras[i]]].insert(id[ras[i]]);
	
	sack[h[node]].insert(id[node]);
	for (pii p:query[node]) if (p.first+h[node]<MAXN) ans[p.second]=sack[p.first+h[node]].size();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>name[i]>>par[i];
		G[par[i]].pb(i);
		compress.pb(name[i]);
	}
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	for (int i=1; i<=n; i++) id[i]=lower_bound(all(compress), name[i])-compress.begin();
	
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>v>>k;
		query[v].pb({k, i});
	}
	dfs1(0);
	dfs2(0);
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}