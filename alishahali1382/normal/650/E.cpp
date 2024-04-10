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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], deg[MAXN];
set<int> st[MAXN];
vector<pii> G1[MAXN], G2[MAXN], E;

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

void join(int x, int y){
	x=get(x);
	y=get(y);
	if (x==y) return ;
	par[y]=x;
	deg[x]+=deg[y];
	deg[y]=0;
	
	if (G1[x].size()<G1[y].size()) G1[x].swap(G1[y]);
	for (pii p:G1[y]) G1[x].pb(p);
	G1[y].clear();
	G1[y].shrink_to_fit();
	
	if (G2[x].size()<G2[y].size()) G2[x].swap(G2[y]);
	for (pii p:G2[y]) G2[x].pb(p);
	G2[y].clear();
	G2[y].shrink_to_fit();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	iota(par, par+MAXN, 0);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		G1[u].pb({u, v});
		G1[v].pb({v, u});
		st[u].insert(v);
		st[v].insert(u);
	}
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G2[u].pb({u, v});
		G2[v].pb({v, u});
		E.pb({u, v});
	}
	for (pii p:E){
		int u=p.first, v=p.second;
		if (st[u].count(v)){
			st[u].erase(v);
			st[v].erase(u);
			ans--;
			deg[get(u)]--;
			deg[get(v)]--;
			join(u, v);
		}
	}
	ans+=n-1;
	cout<<ans<<'\n';
	vector<int> leaf;
	for (int i=1; i<=n; i++) if (deg[i]==1) leaf.pb(i);
	while (ans--){
		//debugv(leaf)
		int v=leaf.back();
		leaf.pop_back();
		if (deg[v]!=1){
			ans++;
			continue ;
		}
		//debug(v)
		pii p;
		while (G1[v].size()){
			p=G1[v].back();
			G1[v].pop_back();
			if (get(p.first)==get(p.second) || !st[p.first].count(p.second)) continue ;
			break ;
		}
		st[p.first].erase(p.second);
		st[p.second].erase(p.first);
		cout<<p.first<<' '<<p.second<<' ';
		int u=get(p.first)^get(p.second)^v;  // get(p.second)
		
		deg[u]--;
		deg[v]--;
		if (deg[u]==1) leaf.pb(u);
		
		while (G2[v].size()){
			p=G2[v].back();
			G2[v].pop_back();
			if (get(p.first)==get(p.second)) continue ;
			break ;
		}
		
		cout<<p.first<<' '<<p.second<<'\n';
				
		join(p.first, p.second);
		if (deg[get(p.first)]==1) leaf.pb(get(p.first));
		
	}
	
	return 0;
}