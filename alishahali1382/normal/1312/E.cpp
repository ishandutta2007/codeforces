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
const int MAXN = 510, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int l=1; l<=n; l++) dp[l][l]=1, sum[l][l]=A[l];
	for (int l=n; l; l--) for (int r=l+1; r<=n; r++){
		dp[l][r]=r-l+1;
		for (int k=l; k<r; k++) dp[l][r]=min(dp[l][r], dp[l][k] + dp[k+1][r]);
		for (int k=l; k<r; k++) if (dp[l][k]==1 && dp[k+1][r]==1){
			if (sum[l][k]==sum[k+1][r]){
				dp[l][r]=1;
				sum[l][r]=sum[l][k]+1;
			}
		}
		
	}
	cout<<dp[1][n]<<'\n';
	
	return 0;
}