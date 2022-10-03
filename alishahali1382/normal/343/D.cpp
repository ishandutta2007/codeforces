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
const int MAXN = 500010, LOG=20;

int n, q, k, u, v, x, y, timer, a, b, ans;
int st[MAXN], fn[MAXN];
int seg[4*MAXN];
int lazy[4*MAXN];
int par[MAXN];
bool mark[4*MAXN];
vector<int> G[MAXN];

void dfs(int node){
	st[node]=++timer;
	for (int v:G[node]) if (!st[v]){
		dfs(v);
		par[v]=node;
	}
	fn[node]=timer;
}

void shift(int id){
	if (!mark[id]) return ;
	mark[id]=0;
	lazy[2*id]=lazy[2*id+1]=lazy[id];
	mark[2*id]=mark[2*id+1]=1;
	seg[2*id]=seg[2*id+1]=lazy[id];
}

int update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return seg[id];
	if (l<=tl && tr<=r){
		lazy[id]=val;
		mark[id]=1;
		return seg[id]=val;
	}
	shift(id);
	int mid=(tl+tr)/2;
	return seg[id]=min(update(2*id, tl, mid, l, r, val), update(2*id+1, mid+1, tr, l, r, val));
}

int get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return inf;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)/2;
	return min(get(2*id, tl, mid, l, r), get(2*id+1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	
	cin>>q;
	while (q--){
		cin>>x>>v;
		if (x==1){
			if (v!=1 && !get(1, 1, n, st[v], fn[v])) update(1, 1, n, st[par[v]], st[par[v]], 0);
			update(1, 1, n, st[v], fn[v], 1);
		}
		if (x==2){
			update(1, 1, n, st[v], st[v], 0);
		}
		if (x==3) cout<<get(1, 1, n, st[v], fn[v])<<'\n';
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