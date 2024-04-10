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
const int MAXN = 202, K=7;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
int A[MAXN], bad[K];
int dp[1<<K][MAXN];
bitset<MAXN> B[1<<K][MAXN];
vector<int> G[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0; i<n*m; i++) cin>>A[i];
	for (int i=0; i<n; i++) for (int j=0; j<m; j++){
		if (i) G[(i-1)*m+j].pb(i*m+j);
		if (j) G[i*m+(j-1)].pb(i*m+j);
		if (i<n-1) G[(i+1)*m+j].pb(i*m+j);
		if (j<m-1) G[i*m+(j+1)].pb(i*m+j);
	}
	memset(dp, 63, sizeof(dp));
	for (int i=0; i<n*m; i++) dp[0][i]=A[i], B[0][i].set(i);
	for (int i=0; i<k; i++){
		cin>>x>>y;
		x--;
		y--;
		
		x=x*m+y;
		//debug(x)
		bad[i]=x;
		dp[1<<i][x]=A[x];
		B[1<<i][x].set(x);
	}
	for (int mask=1; mask<(1<<k); mask++)/* if (__builtin_popcount(mask)>1)*/{
		for (int v=0; v<n*m; v++) for (int sub=mask; sub; sub=(sub-1)&mask) for (int u:G[v]){
			if (dp[sub][v]+dp[mask^sub][u]<dp[mask][v]){
				dp[mask][v]=dp[sub][v]+dp[mask^sub][u];
				B[mask][v]=B[sub][v]|B[mask^sub][u];
			}
		}
		
		for (int v=0; v<n*m; v++) pq.push({dp[mask][v], v});
		while (pq.size()){
			int v=pq.top().second;
			pq.pop();
			for (int u:G[v]) if (dp[mask][v]+A[u]<dp[mask][u]){
				dp[mask][u]=dp[mask][v]+A[u];
				B[mask][u]=B[mask][v];
				B[mask][u].set(u);
				pq.push({dp[mask][u], u});
			}
		}
	}
	
	cout<<dp[(1<<k)-1][bad[0]]<<'\n';
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (B[(1<<k)-1][bad[0]][i*m+j]) cout<<"X";
			else cout<<".";
		}
		cout<<'\n';
	}
	
	
	
	
	return 0;
}