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
const int MAXN = 100010, Z=60;

int n, m, k, u, v, x, y, t, a, b, last;
int A[MAXN];
int h[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int seg[MAXN*Z], N=1;
int L[MAXN*Z], R[MAXN*Z];
int root[MAXN];
vector<int> G[MAXN], level[MAXN];

int Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=N++;
	if (tr-tl==1){
		seg[res]=val;
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Set(L[id], tl, mid, pos, val);
	R[res]=Set(R[id], mid, tr, pos, val);
	seg[res]=min(seg[L[res]], seg[R[res]]);
	return res;
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return inf;
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return min(Get(L[id], tl, mid, l, r), Get(R[id], mid, tr, l, r));
}

void dfs(int node, int par){
	level[h[node]=h[par]+1].pb(node);
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par) dfs(v, node);
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(seg, 63, sizeof(seg));
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(m, m);
	for (int i=1; i<=n; i++){
		root[i]=root[i-1];
		for (int v:level[i]) root[i]=Set(root[i], 1, n+1, stt[v], A[v]), t++;
	}
	cin>>m;
	while (m--){
		cin>>x>>k;
		x=((x+last)%n)+1;
		k=(k+last)%n;
		last=Get(root[min(n, h[x]+k)], 1, n+1, stt[x], fnt[x]);
		cout<<last<<'\n';
	}
	
	return 0;
}