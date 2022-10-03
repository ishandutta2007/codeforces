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
const int mod = 1000000007;
const int MAXN = 1010, K=51;

int n, m, k, u, v, x, y, t, a, b, ans;
short dp[2][MAXN][K][K];
bool good[2][MAXN];

inline void upd(short &a, short b){
	a=max(a, b);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0; i<2; i++){
		cin>>t;
		while (t--) cin>>x, good[i][x]=1;
	}
	m=min(m, 2*n/k+2);
	for (int i=1; i<=n; i++){
		for (int j=0; j<=m; j++){
			for (int x=0; x<=k; x++) for (int y=0; y<=k; y++){
				int tmp=(x && good[0][i]) || (y && good[1][i]);
				upd(dp[1][j][x][y], dp[0][j][max(x-1, 0)][max(y-1, 0)] + tmp);
				if (j){
					upd(dp[1][j][x][y], dp[1][j-1][k][y]);
					upd(dp[1][j][x][y], dp[1][j-1][x][k]);
				}
			}
		}
		
		for (int j=0; j<=m; j++) for (int x=0; x<=k; x++) for (int y=0; y<=k; y++){
			dp[0][j][x][y]=dp[1][j][x][y];
			dp[1][j][x][y]=0;
		}
	}
	cout<<dp[0][m][0][0]<<'\n';
	
	return 0;
}