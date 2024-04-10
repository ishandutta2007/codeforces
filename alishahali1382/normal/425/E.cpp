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
const int MAXN = 510, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll tav[MAXN*MAXN];
ll dp[MAXN][MAXN];

ll get(int i, int j, int k){
	if (!k && !j) return 1;
	if (i==k) return dp[i][j];
	return dp[k][j]*tav[(i-k)*k]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN*MAXN; i++) tav[i]=tav[i-1]*2%mod;
	dp[0][0]=1;
	for (int i=1; i<MAXN; i++){
		//dp[i][0][0]=1;
		for (int j=1; j<=i; j++){
			//for (int k=j; k<i; k++) dp[i][j][k]=dp[k][j][k]*tav[(i-k)*k]%mod;
			for (int kk=0; kk<i; kk++) dp[i][j]=(dp[i][j] + get(i-1, j-1, kk) * (tav[kk]*(tav[i-kk] - 1)%mod))%mod;
		}
	}
	/*
	debug(dp[1][1][1])
	debug(dp[2][1][2])
	debug(dp[2][2][2])
	*/
	cin>>n>>k;
	for (int i=0; i<=n; i++) ans=(ans+get(n, k, i))%mod;
	cout<<ans<<'\n';
	
	return 0;
}