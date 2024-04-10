#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=30010, K=202;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], dp[N][K][2][2];

inline void upd(int &x, int y){ if (x<y) x=y;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(dp, -63, sizeof(dp));
	for (int i=0; i<=n; i++) dp[i][0][0][1]=dp[i][0][1][1]=0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=k; j++){
			for (int a:{0, 1}){
				int z=(a?-1:+1)*(j==1 || j==k?1:2);
				upd(dp[i][j][a][0], dp[i-1][j][a][0] + z*A[i]);
				upd(dp[i][j][a][0], dp[i-1][j-1][a^1][0] + z*A[i]);
				upd(dp[i][j][a][0], dp[i-1][j-1][a^1][1] + z*A[i]);
				if (j==1 || j==k) continue ;
				upd(dp[i][j][a][1], dp[i-1][j][a][1]);
				upd(dp[i][j][a][1], dp[i-1][j-1][a][1]);
				upd(dp[i][j][a][1], dp[i-1][j-1][a][0]);
			}
		}
	}
	for (int i=1; i<=n; i++) for (int a:{0, 1}) upd(ans, dp[i][k][a][0]);
	cout<<ans<<"\n";
	
	return 0;
}