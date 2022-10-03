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
const int MAXN = 200010, LOG=20;

struct DSU{
	int par[MAXN];
	ll sz[MAXN];
	DSU(){ for (int i=1; i<MAXN; i++) par[i]=i, sz[i]=1;}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	ll join(int x, int y){
		x=get(x);
		y=get(y);
		ll res=sz[x]*sz[y];
		par[x]=y;
		sz[y]+=sz[x];
		return res;
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b;
vector<pii> E[MAXN];
ll ans[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		E[x].pb({u, v});
	}
	for (int i=0; i<MAXN; i++){
		ans[i]=ans[i-1];
		for (pii p:E[i]) ans[i]+=dsu.join(p.first, p.second);
	}
	while (m--){
		cin>>x;
		cout<<ans[x]<<' ';
	}
	
	return 0;
}