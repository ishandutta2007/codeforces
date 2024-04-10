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
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN];
int dp2[MAXN];
int G[MAXN][MAXN];
vector<int> DAG[MAXN][MAXN];
vector<int> level[MAXN][MAXN];

void relax(int v){
	//if (dp[v]>dp2[v]+1) cerr<<"relax "<<v<<' '<<dp2[v]+1<<'\n';
	dp[v]=min(dp[v], dp2[v]+1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(G, 63, sizeof(G));
	memset(dp, 63, sizeof(dp));
	cin>>n>>m>>a>>b;
	while (m--){
		cin>>u>>v;
		G[u][v]=1;
	}
	for (int i=1; i<=n; i++) G[i][i]=0;
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
	//debug("floided")
	cin>>k;
	for (int id=1; id<=k; id++){
		cin>>u>>v;
		if (G[u][v]>MAXN){
			id--;
			k--;
			continue ;
		}
		for (int i=1; i<=n; i++) if (G[u][i]+G[i][v]==G[u][v]) level[id][G[i][v]].pb(i)/*, debug2("add", i)*/;
		for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (G[i][j]==1 && G[u][i]+G[j][v]+1==G[u][v]) DAG[id][i].pb(j);
	}
	
	dp[b]=0;
	for (int belman=0; belman<n; belman++){
		//cerr<<endl<<endl;
		for (int id=1; id<=k; id++){
			//debug(id)
			dp2[level[id][0].back()]=dp[level[id][0].back()];
			for (int lv=1; level[id][lv].size(); lv++){
				for (int v:level[id][lv]){
					dp2[v]=0;
					for (int u:DAG[id][v]) dp2[v]=max(dp2[v], dp2[u]);
					dp2[v]=min(dp2[v], dp[v]);
					//cerr<<"dp2["<<v<<"] = "<<dp2[v]<<'\n';
				}
				if (level[id][lv].size()==1) relax(level[id][lv].back());
			}
		}
	}
	if (dp[a]>MAXN) kill(-1);
	kill(dp[a])
	
	return 0;
}
/*
5 6 1 5
1 2
1 3
3 4
2 4
2 5
3 5
3
1 4
2 5
3 5

answer:
2
*/