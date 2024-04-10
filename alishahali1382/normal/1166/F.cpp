#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

vector<int> vec[MAXN];
set<int> G[MAXN];

struct DSU{
	int par[MAXN];
	DSU(){ for (int i=0; i<MAXN; i++) par[i]=i;}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (vec[x].size()>vec[y].size()) swap(x, y);
		for (int v:vec[x]){
			G[v].erase(x);
			G[v].insert(y);
			vec[y].pb(v);
		}
		vec[x].clear();
		par[x]=y;
	}
} dsu;

int n, m, q, u, v, x, y, t, a, b, ans;
map<int, int> mp[MAXN];
char ch;

void addedge(int u, int v, int x){
	if (mp[u].count(x)) dsu.join(mp[u][x], v);
	else mp[u][x]=v;
	if (mp[v].count(x)) dsu.join(mp[v][x], u);
	else mp[v][x]=u;
	G[u].insert(dsu.get(v));
	G[v].insert(dsu.get(u));
	vec[dsu.get(v)].pb(u);
	vec[dsu.get(u)].pb(v);
}

bool query(int u, int v){
	if (dsu.get(u)==dsu.get(v) || G[v].count(dsu.get(u))) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q>>q;
	while (m--){
		cin>>u>>v>>x;
		addedge(u, v, x);
	}
	while (q--){
		cin>>ch>>u>>v;
		if (ch=='?'){
			if (query(u, v)) cout<<"Yes\n";
			else cout<<"No\n";
			continue ;
		}
		cin>>x;
		addedge(u, v, x);
	}
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/