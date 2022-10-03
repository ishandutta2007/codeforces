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
const int MAXN = 100010, LOG=20;

int h[MAXN];

struct DSU{
	int par[MAXN];
	DSU(){
		iota(par, par+MAXN, 0);
	}
	int get(int x){
		return (par[x]==x?x:par[x]=get(par[x]));
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (h[x]>h[y]) swap(x, y);
		par[y]=x;
	}
} dsu;

ll n, m, k, u, v, x, y, t, ans, anss;
ll f[MAXN], a[MAXN], s[MAXN];
int par[MAXN];
vector<int> G[MAXN];

int dfs(int node, int p){
	h[node]=h[p]+1;
	par[node]=p;
	for (int v:G[node]) if (v!=p) s[node]+=dfs(v, node);
	return ++s[node];
}

void Merge(int u, int v){
	u=dsu.get(u);
	v=dsu.get(v);
	anss-=a[u]*(a[u]-1);
	anss-=a[v]*(a[v]-1);
	dsu.join(u, v);
	if (h[u]>h[v]) swap(u, v);
	ans-=f[u]*a[u];
	ans-=f[v]*a[v];
	
	f[u]=f[u]+f[v]-2*s[v]*(n-s[v]);
	f[v]=0;
	a[u]+=a[v];
	a[v]=0;
	anss+=a[u]*(a[u]-1);
	
	ans+=f[u]*a[u];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	anss=n+2*n*(n-1);
	for (int i=1; i<=n; i++){
		a[i]=1;
		f[i]=n*n-(n-s[i])*(n-s[i]);
		for (int v:G[i]) if (h[v]>h[i]) f[i]-=s[v]*s[v];
		ans+=a[i]*f[i];
	}
	//debug2(f[1], f[2])
	//debug(ans)
	cout<<ans-anss<<'\n';
	
	//for (int i=1; i<=n; i++) debug2(i, par[i])
	
	cin>>m;
	while (m--){
		cin>>u>>v;
		while (1){
			u=dsu.get(u);
			v=dsu.get(v);
			//debug2(u, v)
			//debug2(v, par[v])
			if (u==v) break ;
			if (h[u]>h[v]) swap(u, v);
			Merge(v, par[v]);
			//debug2(v, par[v])
			v=par[v];
			//cerr<<'\n';
		}
		//debug2(ans, anss)
		cout<<ans-anss<<'\n';
	}
	//debug2(f[2], f[1])
	
	return 0;
}
/*
30
15 9
19 4
24 1
6 25
11 28
27 9
18 14
18 9
11 21
26 5
13 15
5 30
18 11
10 9
16 17
10 19
9 1
20 13
8 20
5 9
2 15
25 26
14 12
15 29
3 6
7 10
10 16
22 19
23 7
1
8 28


ans:
2686
7018


*/