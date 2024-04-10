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
const int MAXN = 200010;

struct node{
	int c0, c1, lazy;
	void rev(){
		swap(c0, c1);
		lazy^=1;
	}
} seg[4*MAXN];

node combine(node x, node y){
	return {x.c0+y.c0, x.c1+y.c1, 0};
}

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN];
pii A[MAXN];
int st[MAXN], fn[MAXN], timer;
vector<int> child[MAXN];
string s;

void dfs(int node){
	st[node]=++timer;
	for (int v:child[node]) dfs(v);
	fn[node]=timer;
}

node build(int id, int tl, int tr){
	if (tl==tr){
		if (A[tl].first) return seg[id]={0, 1, 0};
		else return seg[id]={1, 0, 0};
	}
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

void shift(int id){
	if (!seg[id].lazy) return ;
	seg[id<<1].rev();
	seg[id<<1 | 1].rev();
	seg[id].lazy=0;
}

node update(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return seg[id];
	if (l<=tl && tr<=r){
		seg[id].rev();
		return seg[id];
	}
	shift(id);
	int mid=(tl+tr)>>1;
	return seg[id]=combine(update(id<<1, tl, mid, l, r), update(id<<1 | 1, mid+1, tr, l, r));
}

int get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return 0;
	if (l<=tl && tr<=r) return seg[id].c1;
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

bool cmp(pii i, pii j){ return st[i.second]<st[j.second];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n; i++){
		cin>>par[i];
		child[par[i]].pb(i);
	}
	for (int i=1; i<=n; i++) cin>>A[i].first, A[i].second=i;
	dfs(1);
	sort(A+1, A+n+1, cmp);
	build(1, 1, n);
	cin>>m;
	while (m--){
		cin>>s>>v;
		if (s=="get") cout<<get(1, 1, n, st[v], fn[v])<<'\n';
		else update(1, 1, n, st[v], fn[v]);
	}
	
	return 0;
}
/*
10
1 2 3 4 2 4 1 7 8
1 1 0 1 1 0 0 0 1 1
1
get 6


*/
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