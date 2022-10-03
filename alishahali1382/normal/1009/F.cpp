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
#define SZ(x) ((int) x.size())

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int h[MAXN];
pii ans[MAXN];
vector<int> vec[MAXN];
vector<int> G[MAXN];

void Merge(int a, int b){ //  a <-- b
	if (SZ(vec[a])<SZ(vec[b])) vec[a].swap(vec[b]);
	int dif=SZ(vec[a])-SZ(vec[b]);
	ans[a]=max(ans[a], ans[b]);
	for (int i=0; i<SZ(vec[b]); i++) ans[a]=max(ans[a], {vec[a][dif+i]+=vec[b][i], dif+i});
	vec[b].clear();
	vec[b].shrink_to_fit(); // :-(
}

void dfs(int node, int par){
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		Merge(node, v);
		h[node]=max(h[node], h[v]+1);
	}
	ans[node]=max(ans[node], {1, SZ(vec[node])});
	vec[node].pb(1);
	//cerr<<"vec["<<node<<"]={";for (int x:vec[node]) cerr<<x<<", ";cerr<<"}\n";
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
	dfs(1, 1);
	//for (int i=1; i<=n; i++) cerr<<i<<" : "<<ans[i].first<<", "<<ans[i].second<<'\n';
	for (int i=1; i<=n; i++) cout<<h[i]-ans[i].second<<'\n';
	
	return 0;
}