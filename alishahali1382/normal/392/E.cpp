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
const int MAXN = 410, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], cost[MAXN];
int dp1[MAXN][MAXN];  // kolesh
int dp2[MAXN][MAXN];  // az l ta r sooodi
int dp3[MAXN][MAXN];  // az l ta r nozooli
int ans[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>cost[i];
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) dp1[i][i]=cost[1];
	for (int l=n; l; l--) for (int r=l+1; r<=n; r++){
		dp1[l][r]=dp2[l][r]=dp3[l][r]=-inf;
		if (A[l]<=A[r]){
			for (int i=l+1; i<=r; i++) if (A[l]+1==A[i]){
				dp2[l][r]=max(dp2[l][r], dp1[l+1][i-1] + dp2[i][r]);
			}
		}
		if (A[l]>=A[r]){
			for (int i=l; i<r; i++) if (A[i]==A[r]+1){
				dp3[l][r]=max(dp3[l][r], dp1[i+1][r-1] + dp3[l][i]);
			}
		}
		for (int i=l; i<r; i++) dp1[l][r]=max(dp1[l][r], dp1[l][i] + dp1[i+1][r]);
		for (int i=l; i<=r; i++) if (A[i]>=max(A[l], A[r]) && 2*A[i]-A[l]-A[r]<MAXN){
			dp1[l][r]=max(dp1[l][r], dp2[l][i] + dp3[i][r] + cost[A[i]-A[l] + A[i]-A[r] + 1]);
		}
	}
	for (int i=1; i<=n; i++){
		ans[i]=ans[i-1];
		for (int j=1; j<=i; j++) ans[i]=max(ans[i], ans[j-1] + dp1[j][i]);
	}
	cout<<ans[n]<<'\n';
	
	return 0;
}