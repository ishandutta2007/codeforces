#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int E[MAXN][2], W[MAXN], P[MAXN];
int sz[MAXN], par[MAXN], cnt;
int ans[MAXN], last;
vector<int> seg[MAXN<<2];
vector<pair<int*,int>> todo;

int get(int x){
	if (par[x]==x) return x;
	return get(par[x]);
}

int join(int x, int y){
	x=get(x);
	y=get(y);
	if (x==y) return 0;
	if (sz[x]<sz[y]) swap(x, y);
	todo.pb({par+y, par[y]});
	todo.pb({sz+x, sz[x]});
	int res=2;
	if (sz[x]&sz[y]&1){
		todo.pb({&cnt, cnt});
		cnt-=2;
		res++;
	}
	sz[x]+=sz[y];
	par[y]=x;
	
	return res;
}

inline void undo(int t=1){
	while (t--){
		(*todo.back().first)=todo.back().second;
		todo.pop_back();
	}
}

void Add(int id, int tl, int tr, int l, int r, int e){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(e);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, e);
	Add(id<<1 | 1, mid, tr, l, r, e);
}

void dfs(int id, int tl, int tr){
	int t=0;
	for (int e:seg[id]) t+=join(E[e][0], E[e][1]);
	if (tr-tl==1){
		while (cnt && last<m){
			last++;
			if (tl<P[last]) continue ;
			Add(1, 1, m+1, P[last], tl, P[last]);
			t+=join(E[P[last]][0], E[P[last]][1]);
		}
		if (cnt) ans[tl]=-1;
		else ans[tl]=W[P[last]];
	}
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1 | 1, mid, tr);
		dfs(id<<1, tl, mid);
	}
	undo(t);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	cnt=n;
	fill(sz+1, sz+n+1, 1);
	iota(par, par+n+1, 0);
	for (int i=1; i<=m; i++) cin>>E[i][0]>>E[i][1]>>W[i], P[i]=i;
	sort(P+1, P+m+1, [](int i, int j){
		return W[i]<W[j];
	});
	dfs(1, 1, m+1);
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}