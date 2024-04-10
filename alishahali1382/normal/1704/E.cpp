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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=1010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll dp[MAXN];
bool mark[MAXN];
vector<int> G[MAXN], GR[MAXN];

ll dfs(int v){
	if (mark[v]) return dp[v];
	mark[v]=1;
	dp[v]=A[v];
	for (int u:GR[v]) dp[v]+=dfs(u);
	return dp[v]%=mod;
}

int Main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		G[i].clear();
		GR[i].clear();
		mark[i]=0;
	}
	for (int i=1; i<=n; i++) cin>>A[i];
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		GR[v].pb(u);
//		debug2(u, v)
	}
//	if (*max_element(A+1, A+n+1)==0) kill(0)
	
	int snk=1;
	while (SZ(G[snk])) snk++;
	dfs(snk);
//	debug(snk)
	
	ans=0;
	for (int tmp=0; tmp<=n+1; tmp++){
		if (A[snk]==0) ans++;
		vector<int> vec;
		for (int i=1; i<=n; i++) if (A[i]){
			A[i]--;
			vec.pb(i);
		}
//		debugv(vec)
		if (vec.empty()) kill(tmp)
		for (int u:vec){
			for (int v:G[u]){
				A[v]++;
			}
		}
//		debug(ans)
	}
	ans=(ans+dp[snk])%mod;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
5 5
1 0 0 0 0
1 2
2 3
3 4
4 5
1 5

1
10 11
998244353 0 0 0 998244353 0 0 0 0 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 3
7 9

*/