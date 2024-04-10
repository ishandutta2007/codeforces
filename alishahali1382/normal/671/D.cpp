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
#define SZ(x) ((int) x.size())

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN];
int par[MAXN];
vector<int> G[MAXN];
set<pii> st[MAXN];
int menha[MAXN];
int ok[MAXN];

void dfs1(int node){
	h[node]=h[par[node]]+1;
	for (int i:G[node]) if (i!=par[node]){
		par[i]=node;
		dfs1(i);
	}
}

void merge(int a, int b){
	if (SZ(st[a])<SZ(st[b])){
		st[a].swap(st[b]);
		swap(menha[a], menha[b]);
	}
	for (pii p:st[b]){
		p.first-=menha[b];
		p.first+=menha[a];
		st[a].insert(p);
	}
	st[b].clear();
	
	if (h[a]>h[b]){
		st[a].swap(st[b]);
		swap(menha[a], menha[b]);
	}
}

void sack(int node){
	for (int i:G[node]) if (i!=par[node]){
		sack(i);
		ok[node]=min(ok[node], ok[i]);
	}
	
	if (ok[node]<h[node]){
		merge(node, par[node]);
		return ;
	}
	while (!st[node].empty()){
		pii p=*st[node].begin();
		st[node].erase(st[node].begin());
		if (h[p.second]>=h[node]) continue ;
		ans+=p.first-menha[node];
		
		menha[node]=p.first;
		ok[node]=h[p.second];
		merge(node, p.second);
		return ;
	}
	
	cout<<"-1\n";
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(ok, 63, sizeof(ok));
	cin>>n>>m;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	while (m--){
		cin>>u>>v>>x;
		st[u].insert({x, v});
	}
	dfs1(1);
	for (int i:G[1]) sack(i);
	cout<<ans<<'\n';
	
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