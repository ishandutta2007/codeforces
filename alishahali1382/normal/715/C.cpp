#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back

const int MAXN = 100010;

ll tav10[MAXN];
ll inv10[MAXN];
ll mod;

// 10**lena * b + a=0

ll calc(vector<ll> &vecin, vector<pll> vecout){ // vecout: {len, a}
	map<ll, int> mp;
	for (ll x:vecin) mp[x]++;
	ll res=0;
	for (pll p:vecout) res+=mp[(mod-p.second)*inv10[p.first]%mod];
	return res;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
bool dead[MAXN];
int sz[MAXN], h[MAXN];
ll val_down[MAXN], val_up[MAXN];
vector<int> G[MAXN];
vector<pii> G2[MAXN];

int dfs_sz(int node, int par){
	sz[node]=1;
	for (int i:G[node]) if (!dead[i] && i!=par) sz[node]+=dfs_sz(i, node);
	return sz[node];
}

int centroid(int node, int par, int n){
	for (int v:G[node]) if (sz[v]*2>n && v!=par && !dead[v]) return centroid(v, node, n);
	return node;
}

void dfs_path(int node, int par, vector<ll> &vecin, vector<pll> &vecout){
	vecin.pb(val_up[node]);
	vecout.pb({h[node]=h[par]+1, val_down[node]});
	for (pii p:G2[node]) if (p.first!=par && !dead[p.first]){
		val_up[p.first]=(tav10[h[node]]*p.second + val_up[node])%mod;
		val_down[p.first]=(val_down[node]*10ll + p.second)%mod;
		dfs_path(p.first, node, vecin, vecout);
	}
}

void solve(int node){
	dfs_sz(node, node);
	int root=centroid(node, node, sz[node]);
	dead[root]=1;
	
	h[root]=0;
	vector<ll> vecin;
	vector<pll> vecout;
	for (pii p:G2[root]) if (!dead[p.first]){
		ll v=p.first, w=p.second;
		val_down[v]=val_up[v]=w;
		vector<ll> vecin_tmp;
		vector<pll> vecout_tmp;
		dfs_path(v, root, vecin_tmp, vecout_tmp);
		ans-=calc(vecin_tmp, vecout_tmp);
		for (ll tmp:vecin_tmp) vecin.pb(tmp);
		for (pll tmp:vecout_tmp) vecout.pb(tmp);
	}
	vecin.pb(0);
	vecout.pb({0, 0});
	ans+=calc(vecin, vecout)-1;
	for (int v:G[root]) if (!dead[v]) solve(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>mod;
	tav10[0]=inv10[0]=1;
	for (int i=1; i<MAXN; i++) tav10[i]=tav10[i-1]*10%mod;
	for (ll i=1; i<11; i++) if ((i*mod+1)%10==0) inv10[1]=(i*mod+1)/10;
	for (int i=2; i<MAXN; i++) inv10[i]=inv10[1]*inv10[i-1]%mod;
	
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		x%=mod;
		G[++u].pb(++v);
		G[v].pb(u);
		G2[u].pb({v, x});
		G2[v].pb({u, x});
	}
	solve(1);
	cout<<ans<<'\n';
	
	return 0;
}