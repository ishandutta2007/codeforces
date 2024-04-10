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
const int MAXN = 2010;

int n, k, ans, u, v;
int dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	fill(dp[1], dp[1]+n+1, 1);
	for (int i=1; i<k; i++){
		for (int j=1; j<=n; j++){
			for (int x=j; x<=n; x+=j) dp[i+1][x]=(dp[i+1][x]+dp[i][j])%mod;
		}
	}
	for (int i=1; i<=n; i++) ans=(ans+dp[k][i])%mod;
	cout<<ans<<endl;
	return 0;
}