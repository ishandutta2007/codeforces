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
const int MAXN = 600010, LOG=20;

int n, m, k1, k2, k3, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][4];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k1>>k2>>k3;
	for (int i=1; i<=k1; i++) cin>>x, A[x]=1;
	for (int i=1; i<=k2; i++) cin>>x, A[x]=2;
	for (int i=1; i<=k3; i++) cin>>x, A[x]=3;
	n=k1+k2+k3;
	//for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	
	memset(dp, 63, sizeof(dp));
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=3; j++){
		dp[i][j]=dp[i][j-1];
		for (int k=1; k<=j; k++) dp[i][j]=min(dp[i][j], dp[i-1][k] + (A[i]!=k));
	}
	
	cout<<dp[n][3]<<'\n';
	
	return 0;
}