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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], h[MAXN], leaf[MAXN];
vector<int> G[MAXN];

void dfs(int node){
	h[node]=h[par[node]]+1;
	leaf[node]=1;
	for (int v:G[node]) if (!h[v]){
		par[v]=node;
		dfs(v);
		leaf[node]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	for (int v=1; v<=n; v++) if (h[v]*k>=n){
		cout<<"PATH "<<h[v]<<"\n";
		while (v){
			cout<<v<<' ';
			v=par[v];
		}
		return 0;
	}
	cout<<"CYCLES\n";
	for (int v=2; v<=n && k; v++) if (leaf[v]){
		k--;
		int done=0, x=0, y=0;
		for (int u:G[v]) if (u!=par[v]){
			if ((h[v]-h[u]+1)%3){
				cout<<h[v]-h[u]+1<<"\n";
				x=v;
				while (1){
					cout<<x<<' ';
					if (x==u) break ;
					x=par[x];
				}
				cout<<"\n";
				done=1;
				break ;
			}
			if (x) y=u;
			else x=u;
		}
		if (done) continue ;
		assert(x && y);
		debug2(x, y)
		if (h[x]<h[y]) swap(x, y);
		cout<<h[x]-h[y]+2<<"\n";
		while (1){
			cout<<x<<' ';
			if (x==y) break ;
			x=par[x];
		}
		cout<<v<<"\n";
	}
	
	
	return 0;
}