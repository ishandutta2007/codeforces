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
const int MAXN=1000010, N=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], src[N], snk[N], adj[1<<N];
bool mark[MAXN];
vector<int> G[MAXN];

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (n==1) kill("YES")
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		mark[v]=1;
	}
	for (int i=1; i<=n; i++) if (!mark[i]) src[t++]=i;
	for (int i=1; i<=n; i++) if (G[i].empty()) snk[k++]=i;
//	assert(k==t);
//	assert(k<=20);
	for (int i=0; i<k; i++){
		memset(mark, 0, sizeof(mark));
		dfs(src[i]);
		for (int j=0; j<k; j++) if (mark[snk[j]]) adj[i]|=(1<<j);
	}
	for (int mask=1; mask<(1<<k)-1; mask++){
		int NS=0;
		for (int i=0; i<k; i++) if (mask&(1<<i)) NS|=adj[i];
		if (__builtin_popcount(NS)<=__builtin_popcount(mask)) kill("NO")
	}
	cout<<"YES\n";
	
	return 0;
}