#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 3010;

ll n, k, ans, a, b;
ll A[MAXN];
ll B[MAXN];
ll C[MAXN];
ll dp[MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	for (int i=1; i<=n; i++) cin>>C[i];
	
	dp[1][0]=A[1];
	dp[1][1]=B[1];
	for (int i=2; i<=n; i++){
		dp[i][0]=max(A[i]+dp[i-1][1], B[i]+dp[i-1][0]);
		dp[i][1]=max(B[i]+dp[i-1][1], C[i]+dp[i-1][0]);
	}/*
	cerr<<endl;
	for (int i=1; i<=n; i++) cerr<<dp[i][0]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) cerr<<dp[i][1]<<' ';cerr<<endl;
	*/
	cout<<dp[n][0]<<endl;
	
	return 0;
}