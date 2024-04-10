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
const int mod = 998244353;
const int MAXN = 1010, AI=100010;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll dp[MAXN][MAXN];
ll F[MAXN];
ll I[MAXN];

ll solve(ll lim){
	for (int i=0; i<=n; i++) for (int j=0; j<=k; j++) dp[i][j]=0;
	dp[0][0]=1;
	for (int i=1; i<=n; i++){
		int ind=upper_bound(A+1, A+i+1, A[i]-lim)-A-1;
		for (int j=0; j<=k; j++){
			dp[i][j]=dp[i-1][j];
			if (ind>=0 && j) dp[i][j]=(dp[i][j]+dp[ind][j-1])%mod;
		}
	}
	return dp[n][k];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	for (int lim=1; lim*(k-1)<AI; lim++) ans+=solve(lim);
	cout<<ans%mod<<'\n';
	
	return 0;
}