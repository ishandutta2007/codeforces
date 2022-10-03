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

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], deg[MAXN];
int par[MAXN], h[MAXN], parid[MAXN];
ll F[MAXN], ans=1;
int f[MAXN][2], nex2[MAXN], bad[MAXN];
bool mark[MAXN];
vector<pii> G[MAXN];
map<pii, int> mp;
map<int, int> nex[MAXN];
set<pii> st;

void dfs(int node){
	h[node]=h[par[node]]+1;
	for (pii p:G[node]) if (p.first!=par[node]){
		par[p.first]=node;
		parid[p.first]=p.second;
		dfs(p.first);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		mp[{u, v}]=mp[{v, u}]=i;
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	dfs(1);
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (!A[i]) continue ;
		int v=i, u=A[i];
		if (u==v) kill(0)
		vector<int> v1, v2;
		while (u!=v){
			if (h[u]<h[v]){
				v1.pb(v);
				v=par[v];
			}
			else{
				v2.pb(u);
				u=par[u];
			}
		}
		v1.pb(u);
		reverse(all(v2));
		for (int x:v2) v1.pb(x);
		for (int i=1; i<v1.size(); i++){
			pii p={v1[i-1], v1[i]};
			if (st.count(p)) kill(0)
			st.insert(p);
			int id=mp[{v1[i-1], v1[i]}];
			if (i==1) f[v1[i-1]][0]=id;
			if (i==v1.size()-1) f[v1[i]][1]=id;
			if (1<i && i<v1.size()-1){
				if (f[v1[i]][1]==id) kill(0)
				if (f[v1[i-1]][0]==id) kill(0)
			}
		}
		for (int i=1; i+1<v1.size(); i++){
			int x=mp[{v1[i-1], v1[i]}];
			int y=mp[{v1[i+1], v1[i]}];
			if (nex[v1[i]][x]) kill(0)
			nex[v1[i]][x]=y;
		}
	}
	for (int i=1; i<=n; i++){
		int ted=G[i].size()-(f[i][0]>0)-(f[i][1]>0)-nex[i].size();
		for (pii p:nex[i]) nex2[p.first]=p.second, bad[p.second]=1;
		if (f[i][0] && f[i][1]){
			int v=f[i][0], l=0;
			while (nex2[v]) v=nex2[v], l++;
			if (v==f[i][1] && l<G[i].size()-1) kill(0)
		}
		for (pii p:G[i]){
			int v=p.second;
			if (bad[v]) continue ;
			while (1){
				if (mark[v]) kill(0)
				mark[v]=1;
				if (!nex2[v]) break ;
				v=nex2[v];
			}
		}
		for (pii p:G[i]) if (!mark[p.second]) kill(0)
		ans=ans*F[max(ted, 0)]%mod;
		for (pii p:G[i]) nex2[p.second]=mark[p.second]=bad[p.second]=0;
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
6
1 2
2 6
2 3
3 4
3 5
6 1 4 5 2 3

3
1 2
2 3
2 1 0

*/