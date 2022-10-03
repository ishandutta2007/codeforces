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
const int MAXN = 110, K=23;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][K][K];
ll dpp[K][K];
ll sz[MAXN];
vector<int> G[MAXN];

void dfs(int node, int par){
	sz[node]=1;
	dp[node][1][0]=dp[node][0][1]=1;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		for (int i=0; i<=k+1; i++) for (int j=0; j<=k+1; j++) dpp[i][j]=dp[node][i][j], dp[node][i][j]=0;
		for (int good1=-1; good1<=min(sz[node], k); good1++)
			for (int bad1=-1; bad1<=min(sz[node], k); bad1++)
				for (int good2=-1; good2<=min(sz[v], k); good2++)
					for (int bad2=-1; bad2<=min(sz[v], k/*-1*/); bad2++){
						int good=inf, bad=-inf;
						if (good1!=-1) good=min(good, good1);
						if (good2!=-1) good=min(good, good2+1);
						if (bad1!=-1) bad=max(bad, bad1);
						if (bad2!=-1) bad=max(bad, bad2+1);
						
						
						if (bad>k) continue ; // unneccesary
						if (good!=inf && bad!=-inf && good+bad<=k) bad=-1;
						if (good>k) good=-1;
						if (bad<-k) bad=-1;
						/*
						if (node==2){
							debug2(good1, bad1)
							debug2(good2, bad2)
							debug2(good, bad)
							cerr<<'\n';
						}*/
						
						dp[node][good+1][bad+1]=(dp[node][good+1][bad+1] + dpp[good1+1][bad1+1]*dp[v][good2+1][bad2+1])%mod;
					}
		
		sz[node]+=sz[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	for (int i=1; i<=k+1; i++) ans+=dp[1][i][0];
	cout<<ans%mod<<'\n';
	/*
	debug(dp[1][1][0])
	
	debug(dp[2][1][0])
	debug(dp[2][2][0])
	debug(dp[2][0][2]) //  wrong!
	*/
	
	return 0;
}