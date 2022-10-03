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
#define upd(x, y) x=min(x, y)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(dp, 63, sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=0;
	for (int i=1; i<=n; i++){
		for (int a=0; a<=i; a++){
			if (A[i]){
				int typ=A[i]%2;
				if (a-typ>=0) dp[i][a][typ]=min(dp[i-1][a-typ][typ], dp[i-1][a-typ][1-typ] + 1);
				continue ;
			}
			upd(dp[i][a][0], dp[i-1][a][0]);
			upd(dp[i][a][0], dp[i-1][a][1] + 1);
			
			if (a){
				upd(dp[i][a][1], dp[i-1][a-1][1]);
				upd(dp[i][a][1], dp[i-1][a-1][0] + 1);
			}
		}
	}
	ans=min(dp[n][(n+1)/2][0], dp[n][(n+1)/2][1]);
	cout<<ans<<'\n';
	
	return 0;
}
/*
2
1 0

*/