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
const int MAXN = 510, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
char A[MAXN][MAXN];
ll dp[2][MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (n==m && n==1) kill(1)
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>A[i][j];
	if (A[0][0]!=A[n-1][m-1]) kill(0);
	dp[0][0][n-1]=1;
	int prev=0, curr=1;
	for (int i=1; 2*i<=n+m; i++){
		memset(dp[curr], 0, sizeof(dp[curr]));
		for (int j=0; j<n; j++) for (int k=j; k<n; k++){
			int x=j, y=i-j;
			int xx=k, yy=n+m-2-i-xx;
			if (y<0 || y>=m || yy<0 || yy>=m || A[x][y]!=A[xx][yy]) continue ;
			dp[curr][x][xx]+=dp[prev][x][xx];
			if (x) dp[curr][x][xx]+=dp[prev][x-1][xx];
			dp[curr][x][xx]+=dp[prev][x][xx+1];
			if (x) dp[curr][x][xx]+=dp[prev][x-1][xx+1];
			dp[curr][x][xx]%=mod;
			/*
			debug2(x, y)
			debug2(xx, yy)
			debug(dp[curr][x][xx]) 
			cerr<<endl;
			*/
		}
		//debug(i)
		if ((n+m)%2 && 2*i+2==n+m-1){
			for (int x=0; x<n; x++) ans+=dp[curr][x][x]+dp[curr][x][x+1];
			break ;
		}
		if ((n+m)%2==0 && 2*i+2==n+m){
			/*
			debug("meet")
			debug(dp[curr][0][0])
			debug(dp[curr][1][1])
			*/
			for (int x=0; x<n; x++) ans+=dp[curr][x][x];
			break ;
		}
		
		swap(prev, curr);
	}
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}
/*
2 4
aaaa
aaaa

*/