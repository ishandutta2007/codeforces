#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 200010;

int n, k, x;
int A[110];
int B[110];
int dp[110][MAXN];

int f(int i, int j){
	if (i==0 && j==0) return 0;
	if (i<=0) return -inf;
	if (dp[i][j+100000]!=-1) return dp[i][j+100000];
	//cerr<<"f "<<i<<' '<<j<<endl;
	return dp[i][j+100000]=max(f(i-1, j), f(i-1, j-B[i]) + A[i]);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		cin>>x;
		B[i]=A[i]-x*k;
	}
	memset(dp, -1, sizeof(dp));
	int ans=f(n, 0);
	if (!ans) ans--;
	cout<<ans<<endl;
	return 0;
}