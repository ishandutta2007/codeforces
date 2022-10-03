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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=27;

int n, m, k, u, v, x, y, t, a, b, ans;
int fib[LOG], ok[MAXN], sz[MAXN], par[MAXN];
vector<int> G[MAXN], comp;

int dfs1(int node, int p){
	sz[node]=1;
	par[node]=p;
	comp.pb(node);
	for (int v:G[node]) if (v!=par[node]) sz[node]+=dfs1(v, node);
	return sz[node];
}
void rem(int x, int y){
	for (int &v:G[x]) if (v==y) swap(G[x].back(), v);
	G[x].pop_back();
}
bool Decompose(int node){
	comp.clear();
	dfs1(node, 0);
	if (sz[node]==1) return 1;
	int f=ok[sz[node]];
	if (!f) return 0;
	int x=0, y=0;
	for (int v:comp){
		if (sz[v]==fib[f-1] || sz[v]==fib[f-2]){
			x=v;
			y=par[v];
			break ;
		}
	}
	if (!x) return 0;
	rem(x, y);
	rem(y, x);
	return Decompose(x) && Decompose(y);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fib[0]=fib[1]=ok[1]=1;
	for (int i=2; i<LOG; i++){
		fib[i]=fib[i-1]+fib[i-2];
		ok[fib[i]]=i;
//		debug2(i, fib[i])
	}
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	if (Decompose(1)) kill("YES")
	kill("NO")
	
	return 0;
}