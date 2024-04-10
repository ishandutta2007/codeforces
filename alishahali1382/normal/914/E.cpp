#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

const int MAXN = 200010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
ll ans[MAXN];
bool dead[MAXN];
ll tsum[MAXN];
int sz[MAXN];
char ch[MAXN];
int cnt[1<<20];
vector<int> G[MAXN];

int dfs_sz(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (!dead[v] && v!=par) sz[node]+=dfs_sz(v, node);
	return sz[node];
}

ll dfs_sum(int node, int par){
	for (int v:G[node]) if (!dead[v] && v!=par) tsum[node]+=dfs_sum(v, node);
	return tsum[node];
}

void dfs_ans(int node, int par){
	ans[node]+=tsum[node];
	tsum[node]=0;
	for (int v:G[node]) if (!dead[v] && v!=par) dfs_ans(v, node);
}

int centroid(int node, int par, int n){
	for (int v:G[node]) if (v!=par && !dead[v] && sz[v]*2>=n) return centroid(v, node, n);
	return node;
}

void dfs_path(int node, int par, int h, vector<pii> &vec){
	vec.pb({h^=(1<<(ch[node]-'a')), node});
	tsum[node]=0;
	for (int v:G[node]) if (v!=par && !dead[v]) dfs_path(v, node, h, vec);
}

void calc(vector<pii> &vec, int x, int z){
	for (pii p:vec) cnt[p.first]++;
	for (pii p:vec){
		ll tmp=cnt[p.first^x];
		for (int i=0; i<20; i++) tmp+=cnt[p.first^x^(1<<i)];
		tsum[p.second]+=tmp*z;
	}
	for (pii p:vec) cnt[p.first]--;
}

void solve(int node){
	dfs_sz(node, node);
	int root=centroid(node, node, sz[node]);
	
	dead[root]=1;
	vector<pii> vec;
	vec.pb({0, root});
	for (int v:G[root]) if (!dead[v]){
		vector<pii> tmp;
		dfs_path(v, root, 0, tmp);
		for (auto it:tmp) vec.pb(it);
		calc(tmp, (1<<(ch[root]-'a')), -1);
	}
	calc(vec, (1<<(ch[root]-'a')), 1);
	dfs_sum(root, root);
	tsum[root]=(tsum[root]+1)/2;
	dfs_ans(root, root);
	
	for (int v:G[root]) if (!dead[v]) solve(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) cin>>ch[i];
	solve(1);
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';cout<<'\n';
	
	return 0;
}