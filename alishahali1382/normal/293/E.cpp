#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
const int MAXN = 100010;

int BIT[MAXN];
inline void add(int id){ for (; id<MAXN; id+=id&(-id)) BIT[id]++;}
inline void reset(int id){ for (; id<MAXN; id+=id&(-id)) BIT[id]=0;}
inline int get(int id){
	int res=0;
	for (; id; id-=id&(-id)) res+=BIT[id];
	return res;
}

int W, L;

ll calc(vector<pii> &vec){
	sort(all(vec));
	
	int n=vec.size(), pointer=0;
	ll res=0;
	for (int i=n-1; i>=0; i--) if (vec[i].first<=W){
		while (pointer<n && vec[pointer].first+vec[i].first<=W) add(vec[pointer++].second);
		res+=get(max(0, L-vec[i].second));
	}
	for (pii p:vec){
		res-=(p.first*2<=W && p.second*2<=L);
		reset(p.second);
	}
	return res>>1;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
int sz[MAXN];
bool dead[MAXN];
vector<int> G[MAXN];
vector<pii> G2[MAXN];
vector<pii> vec[MAXN];

int dfs1(int node, int par){
	sz[node]=1;
	for (int i:G[node]) if (!dead[i] && i!=par) sz[node]+=dfs1(i, node);
	return sz[node];
}

int centroid(int node, int par, int n){
	for (int v:G[node]) if (!dead[v] && v!=par && sz[v]*2>n) return centroid(v, node, n);
	return node;
}

void dfs2(int node, int par, int l, int w, vector<pii> &V){
	if (l>L || w>W) return ;
	V.pb({w, l});
	for (pii p:G2[node]) if (p.first!=par && !dead[p.first]) dfs2(p.first, node, l+1, w+p.second, V);
}

void solve(int root){
	dfs1(root, root);
	root=centroid(root, root, sz[root]);
	for (pii p:G2[root]) if (!dead[p.first]){
		dfs2(p.first, root, 1, p.second, vec[p.first]);
		ans+=vec[p.first].size()-calc(vec[p.first]);
		for (auto tmp:vec[p.first]) vec[root].pb(tmp);
		vec[p.first].clear();
	}
	ans+=calc(vec[root]);
	vec[root].clear();
	dead[root]=1;
	for (int v:G[root]) if (!dead[v]) solve(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>L>>W;
	for (int i=2; i<=n; i++){
		cin>>x>>y;
		G[x].pb(i);
		G[i].pb(x);
		G2[x].pb({i, y});
		G2[i].pb({x, y});
	}
	solve(1);
	cout<<ans<<'\n';
	
	return 0;
}