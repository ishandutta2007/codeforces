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
const int MAXN = 500010, Z=22;

int n, m, k, u, v, x, y, t, a, b, cnt;
int A[MAXN], ans[MAXN];
int seg[MAXN<<2], N;
bool mark[MAXN*Z];
vector<int> G[MAXN*Z], topol;
queue<int> Q;

void addedge(int u, int v){
	//debug2(u, v)
	G[v].pb(u);
	//G[u].pb(v);
	//deg[v]++;
}

int Build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=tl;
	int mid=(tl+tr)>>1;
	seg[id]=++N;
	addedge(Build(id<<1, tl, mid), seg[id]);
	addedge(Build(id<<1 | 1, mid, tr), seg[id]);
	return seg[id];
}

void Rem(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return ;
	seg[id]=++N;
	if (tr-tl==1) return ;
	int mid=(tl+tr)>>1;
	Rem(id<<1, tl, mid, pos);
	Rem(id<<1 | 1, mid, tr, pos);
	addedge(seg[id<<1], seg[id]);
	addedge(seg[id<<1 | 1], seg[id]);
}

void Addedge(int id, int tl, int tr, int l, int r, int v){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		addedge(seg[id], v);
		return ;
	}
	int mid=(tl+tr)>>1;
	Addedge(id<<1, tl, mid, l, r, v);
	Addedge(id<<1 | 1, mid, tr, l, r, v);
}

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
	if (node<=n) ans[node]=++cnt;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	N=n;
	Build(1, 1, n+1);
	for (int i=1; i<=n; i++){
		if (A[i]==-1){
			Addedge(1, 1, n+1, 1, i, i);
			Addedge(1, 1, n+1, i+1, n+1, i);
		}
		else{
			Addedge(1, 1, n+1, 1, min(i, A[i]), i);
			Addedge(1, 1, n+1, i+1, A[i], i);
			addedge(i, A[i]);
			Rem(1, 1, n+1, A[i]);
		}
	}/*
	for (int i=1; i<=N; i++) if (!deg[i]) Q.push(i);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		//topol.pb(v);
		if (v<=n) ans[v]=++cnt;
		for (int u:G[v]) if (!--deg[u]) Q.push(u);
	}*/
	for (int i=1; i<=N; i++) if (!mark[i]) dfs(i);
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	cout<<'\n';
	
	return 0;
}