#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 200010, LOG=17;

struct INTERVAL{
	int l, r, mx;
	ld prob;
	bool operator <(INTERVAL I){
		if (r-l==I.r-I.l) return l<I.l;
		return r-l>I.r-I.l;
	}
} B[5010];

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN][LOG];
int par[5010];
ld dp[5010][5010];
vector<int> child[5010];

int RMQ(int l, int r){ // [l, r)
	int lg=log2(r-l);
	return max(A[l][lg], A[r-(1<<lg)][lg]);
}

void dfs(int node){
	dp[node][0]=1-B[node].prob;
	if (child[node].empty()){
		for (int j=1; j<=5009; j++) dp[node][j]=1;
		return ;
	}
	for (int v:child[node]){
		dfs(v);
		dp[node][0]*=dp[v][min(B[node].mx-B[v].mx, 5009)];
	}
	for (int j=1; j<=5009; j++){
		ld val0=1-B[node].prob, val1=B[node].prob;
		for (int v:child[node]){
			val0*=dp[v][min(B[node].mx+j-B[v].mx, 5009)];
			val1*=dp[v][min(B[node].mx+j-B[v].mx-1, 5009)];
		}
		dp[node][j]=val0+val1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i][0];
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++) A[i][j]=max(A[i][j-1], A[i+(1<<(j-1))][j-1]);
	
	for (int i=1; i<=k; i++) cin>>B[i].l>>B[i].r>>B[i].prob;
	B[++k]={1, n, 0, 0};
	sort(B+1, B+k+1);
	for (int i=2; i<=k; i++){
		for (int j=i-1; j; j--) if (B[j].l<=B[i].l && B[i].r<=B[j].r){
			par[i]=j;
			child[j].pb(i);
			break ;
		}
	}
	for (int i=1; i<=k; i++) B[i].mx=RMQ(B[i].l, B[i].r+1);
	dfs(1);
	
	ld ans=RMQ(1, n+1);
	for (ll i=1; i<5010; i++) ans+=(dp[1][i]-dp[1][i-1])*i;
	cout<<setprecision(12)<<fixed<<ans<<'\n';
	
	return 0;
}