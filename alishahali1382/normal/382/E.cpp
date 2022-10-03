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
const int MAXN = 52;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][MAXN][2];
ll C[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	C[0][0]=1;
	for (int i=1; i<MAXN; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n>>k;
	dp[1][0][0]=1;
	for (int i=2; i<=n; i++) for (int j=1; j<=k; j++){
		dp[i][j][0]=dp[i-1][j][1]*(i-1)%mod;
		dp[i][j][1]=dp[i-1][j-1][0]*(i-1)%mod;
		for (int L=1; L<i-1; L++) for (int kk=0; kk<=j; kk++){
			ll tmp=C[i-2][L-1]*L*(i-L-1)%mod;
			dp[i][j][0]+=((dp[L][kk][1]*dp[i-L-1][j-kk][1])%mod)*tmp%mod;
			if (kk<j) dp[i][j][1]+=((dp[L][kk][1]*dp[i-L-1][j-kk-1][0] + dp[L][kk][0]*dp[i-L-1][j-kk-1][1] + dp[L][kk][0]*dp[i-L-1][j-kk-1][0])%mod)*tmp%mod;
		}
		dp[i][j][0]%=mod;
		dp[i][j][1]%=mod;
		if (dp[1][1][0]) debug2(i, j)
	}
	
	ans=(dp[n][k][0] + dp[n][k][1])%mod;
	cout<<ans<<'\n';
	
	return 0;
}