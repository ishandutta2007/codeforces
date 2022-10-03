#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 40010;

int n, a, b, c;
int dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>a>>b>>c;
	for (int i=1; i<=n; i++){
		dp[i]=-inf;
		if (a<=i) dp[i]=max(dp[i], dp[i-a]+1);
		if (b<=i) dp[i]=max(dp[i], dp[i-b]+1);
		if (c<=i) dp[i]=max(dp[i], dp[i-c]+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}