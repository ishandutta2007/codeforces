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
const int MAXN = 82, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
int A[MAXN][MAXN];
bool mark[MAXN];
int dp[6][MAXN];
int dist[MAXN][MAXN];
vector<pii> ST[MAXN][MAXN];
vector<int> vec;

void solve(){
	//for (int i:vec) for (int j:vec) for (int k:vec) ST[i][j].erase(ST[i][j].find(A[i][k]+A[k][j]));
	
	for (int i:vec) for (int j:vec) for (int x=0; ; x++) if (!mark[ST[i][j][x].second]){
		dist[i][j]=ST[i][j][x].first;
		break ;
	}
	/*
	if (vec.size()==2 && vec.back()==2){
		debug(mark[5])
		debugv(vec)
		for (int u:vec) for (int v:vec) cerr<<u<<' '<<v<<" : "<<dist[u][v]<<'\n';
	}
	*/
	for (int i=0; i<=k; i++) for (int v:vec) dp[i][v]=inf;
	dp[0][1]=0;
	for (int i=1; i<=k; i++) for (int u:vec) for (int v:vec) dp[i][v]=min(dp[i][v], dp[i-1][u]+dist[u][v]);
	ans=min(ans, dp[k][1]);
	
	//for (int i:vec) for (int j:vec) for (int k:vec) ST[i][j].insert(A[i][k]+A[k][j]);
}

void BT(){
	if (vec.size()<n) solve();
	if (vec.size()==k) return ;
	for (int i=vec.back()+1; i<=n; i++) if (!mark[i]){
		mark[i]=1;
		vec.pb(i);
		BT();
		vec.pop_back();
		mark[i]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	k/=2;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin>>A[i][j];
	for (int mid=1; mid<=n; mid++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ST[i][j].pb({A[i][mid]+A[mid][j], mid});
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) sort(all(ST[i][j]));//, ST[i][j].resize(min(n, k+1));
	
	vec.pb(1);
	mark[1]=1;
	BT();
	cout<<ans<<'\n';
	
	return 0;
}