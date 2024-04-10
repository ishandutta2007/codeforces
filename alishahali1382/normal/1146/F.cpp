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
const int mod = 998244353;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN];
ll dp[MAXN][3];
vector<int> G[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n; i++) cin>>par[i], G[par[i]].pb(i);
	for (int i=n; i; i--){
		if (G[i].empty()){
			dp[i][2]=1;
			continue ;
		}
		dp[i][0]=1;
		for (int j:G[i]){
			dp[i][2]=(dp[i][2]*(dp[j][0]+dp[j][1]+2*dp[j][2]) + dp[i][1]*(dp[j][1]+dp[j][2]))%mod;
			dp[i][1]=(dp[i][1]*(dp[j][0]+dp[j][2]) + dp[i][0]*(dp[j][1]+dp[j][2]))%mod;
			dp[i][0]=(dp[i][0]*(dp[j][0]+dp[j][2]))%mod;
			//cerr<<"dp : "<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
		}
	}
	cout<<(dp[1][0]+dp[1][2])%mod<<'\n';
	
	return 0;
}