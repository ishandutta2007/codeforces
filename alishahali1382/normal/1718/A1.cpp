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
const int mod=1000000007;
const int MAXN=5010, N=13;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][1<<N];

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		int mn=inf;
		for (int j=0; j<(1<<N); j++){
			int x=(A[i]^j);
			dp[i][j]=dp[i-1][x] + (x>0);
			mn=min(mn, dp[i][j]);
		}
		for (int j=0; j<(1<<N); j++){
			dp[i][j]=min(dp[i][j], mn+1);
		}
	}
	kill(dp[n][0])
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(dp[0], 31, sizeof(dp[0]));
	dp[0][0]=0;
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}