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
const int MAXN=400010, LOG=30;

int n, m, k, u, v, x, y, t, a, b, root, ans;
pii A[MAXN], V[MAXN];
int par[MAXN], sum[MAXN];
bool is[MAXN];
vector<int> G[MAXN], grundy;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int GetH(pii p){ return p.first+p.second;}
inline pii GetPar(pii p, int k){
	int x=p.first, y=p.second;
	while (k){
		int xx=(x&-x), yy=(y&-y);
		if (!xx) xx=2*inf;
		if (!yy) yy=2*inf;
		int tmp=min(k, min(xx, yy));
		k-=tmp;
		if (xx<yy) x-=tmp;
		else y-=tmp;
	}
	return {x, y};
}
inline int Zone(pii p, int n){
    if (p.first&(1<<(n-1))) return 2;
    if (p.second&(1<<(n-1))) return 1;
    return 0;
}
void dfs_order(vector<pii> &vec, int n=LOG) {
	if (n==0 || vec.size()==0) return ;
	vector<pii> v[3];
	for (pii p:vec) {
		int z=Zone(p, n);
		p.first&=(1<<(n-1))-1;
		p.second&=(1<<(n-1))-1;
		v[z].pb(p);
    }
	vec.clear();
	for (int i:{0, 1, 2}) dfs_order(v[i], n-1);
	for (pii p:v[0]) if (!p.first) vec.pb(p);
    for (pii p:v[1]) vec.pb({p.first, p.second|(1<<(n-1))});
    for (pii p:v[0]) if (p.first) vec.pb(p);
    for (pii p:v[2]) vec.pb({p.first|(1<<(n-1)), p.second});
}
pii Lca(pii u, pii v, int n=LOG) {
	if (n==0) return {0, 0};
	int zu = Zone(u, n), zv = Zone(v, n);
	if (zu > zv) swap(u, v), swap(zu, zv);
	u.first&=(1<<(n-1))-1;
	u.second&=(1<<(n-1))-1;
	v.first&=(1<<(n-1))-1;
	v.second&=(1<<(n-1))-1;
	if (zu == 1 && zv == 2) return {0, 0};
	if (zu == 2 && zv == 2){
		pii A = Lca(u, v, n-1);
		return {A.first+(1<<(n-1)), A.second};
	}
	if (zu == 1 && zv == 1) {
		pii A = Lca(u, v, n-1);
		return {A.first, A.second+(1<<(n-1))};
	}
	if (zv == 1) return Lca(u, {0, (1<<(n-1))-1}, n-1);
	if (zv == 2) return Lca(u, {(1<<(n-1))-1, 0}, n-1);
	return Lca(u, v, n-1);
}
inline int GetId(pii p){
	return lower_bound(V, V+n, p)-V;
}
inline bool IsPar(pii u, pii v){
	if (GetH(u)>GetH(v)) return 0;
	return GetPar(v, GetH(v)-GetH(u))==u;
}
int dfs(int node){
	for (int v:G[node]) sum[node]+=dfs(v);
	return sum[node];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pii> vec;
	cin>>m;
	for (int i=0; i<2*m; i++) cin>>A[i].first>>A[i].second, vec.pb(A[i]);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	dfs_order(vec);
	for (int i=vec.size()-1; i; i--) vec.pb(Lca(vec[i], vec[i-1]));
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	dfs_order(vec);
	n=vec.size();
	
	for (int i=0; i<n; i++) V[i]=vec[i];
	sort(V, V+n);
	vector<int> stk={root=GetId(vec[0])};
	for (int i=1; i<n; i++){
		int v=GetId(vec[i]);
		while (!IsPar(V[stk.back()], V[v])) stk.pop_back();
		par[v]=stk.back();
		G[stk.back()].pb(v);
		stk.pb(v);		
	}
	
	for (int i=0; i<2*m; i+=2){
		int u=GetId(A[i]), v=GetId(A[i+1]), lca=GetId(Lca(A[i], A[i+1]));
		sum[u]++;
		sum[v]++;
		sum[lca]-=2;
		is[lca]=1;
	}
	dfs(root);
	for (int v=0; v<n; v++){
		if (sum[v]){
			grundy.pb(GetH(V[par[v]])+1);
			grundy.pb(GetH(V[v])+1);
		}
		else if (is[v]){
			grundy.pb(GetH(V[v]));
			grundy.pb(GetH(V[v])+1);
		}
	}
	sort(all(grundy));
	vec.clear();
	int last=-1;
	for (int x:grundy){
		if (last==-1){
			if (vec.empty() || vec.back().second<x) last=x;
			else{
				last=vec.back().first;
				vec.pop_back();
			}
		}
		else{
			if (last<x) vec.pb({last, x});
			last=-1;
		}
	}
	ans=2*vec.size();
	if (ans && vec[0].first==0) ans--;
	cout<<ans<<"\n";
	
	return 0;
}
/*
input format:
m
x1 y1 x2 y2
x1 y1 x2 y2
...
x1 y1 x2 y2
[m+1 lines]

1<=m<=100000
0<=x,y<=1000000000


2
0 6 4 0
1 4 1 4

*/