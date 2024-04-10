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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
pair<int, pair<int, pii>> ans;
pii h[MAXN][2];
pii h2[MAXN];
int stt[MAXN], fnt[MAXN], timer=0;
vector<int> G[MAXN];
map<int, pii> mp[MAXN];

void dfs1(int node, int par){
	stt[node]=timer++;
	h[node][0]={0, node};
	for (int v:G[node]) if (v!=par){
		dfs1(v, node);
		pii p={h[v][0].first+1, h[v][0].second};
		mp[node][v]=p;
		if (p>h[node][0]) swap(p, h[node][0]);
		if (p>h[node][1]) swap(p, h[node][1]);
	}
	fnt[node]=timer;
}

bool is_par(int u, int v){
	return stt[u]<=stt[v] && fnt[v]<=fnt[u];
}

void dfs2(int node, int par){
	h2[node]={0, node};
	if (par){
		h2[node]=max(h2[node], pii(h2[par].first+1, h2[par].second));
		if (is_par(node, h[par][0].second)) h2[node]=max(h2[node], pii(h[par][1].first+1, h[par][1].second));
		else h2[node]=max(h2[node], pii(h[par][0].first+1, h[par][0].second));
		mp[node][par]=h2[node];
	}
	for (int v:G[node]) if (v!=par) dfs2(v, node);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1, 0);
	/*
	for (int i=1; i<=n; i++){
		debug(i)
		debugp(h[i][0])
		debugp(h[i][1])
		cerr<<'\n';
	}
	*/
	dfs2(1, 0);
	/*
	for (int i=1; i<=n; i++){
		debug(i)
		debugp(h2[i])
		cerr<<'\n';
	}*/
	vector<pii> vec;
	for (int i=1; i<=n; i++) if (G[i].size()>=2){
		vec.clear();
		vec.pb({0, i});
		for (int v:G[i]) vec.pb(mp[i][v]);
		sort(all(vec));
		reverse(all(vec));
		/*
		if (i==3){
			debug(i)
			for (pii p:vec) debugp(p)
			cerr<<'\n';
		}*/
		ans=max(ans, make_pair(vec[0].first+vec[1].first+vec[2].first, make_pair(vec[0].second, pii(vec[1].second, vec[2].second))));
	}
	cout<<ans.first<<'\n';
	cout<<ans.second.first<<' '<<ans.second.second.first<<' '<<ans.second.second.second<<'\n';
	
	return 0;
}