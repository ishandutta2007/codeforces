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
#define addmod(x, y) (x=((x)+(y))%mod)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 210, constant=5;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][MAXN][MAXN*constant];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	//reverse(A+1, A+n+1);
	
	/*
	cerr<<endl;
	for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl<<endl;
	*/
	
	dp[0][0][0]=1;
	for (int i=0; i<n; i++) for (int j=0; j<=i; j++) for (int k=0; k<=m; k++) if (dp[i][j][k]){
		int tmp1=k+(A[i+1]-A[i])*j, tmp2=k+(A[i+1]-A[i])*(j-1);
		if (tmp1>m) continue ;
		if (j) addmod(dp[i+1][j][tmp1], 1ll*dp[i][j][k]*j%mod);
		
		addmod(dp[i+1][j][tmp1], dp[i][j][k]);
		
		if (tmp1<=m) addmod(dp[i+1][j+1][tmp1], dp[i][j][k]);
		
		/*if (k+tmp2<=m && j) */
		if (j && tmp1<=m) addmod(dp[i+1][j-1][tmp1], 1ll*dp[i][j][k]*j%mod);
		
	}
	/*
	debug(dp[2][0][2])
	debug(dp[1][1][0])
	
	cerr<<endl;
	debug(dp[3][0][0])
	debug(dp[3][0][1])
	debug(dp[3][0][2])
	//debug(dp[3][0][3])
	*/
	
	/*
	debug(dp[4][0][0])
	debug(dp[4][0][1])
	debug(dp[4][0][2])
	debug(dp[4][0][3])
	cerr<<endl;
	*/
	for (int i=0; i<=m; i++) ans=(ans+dp[n][0][i])%mod;
	cout<<ans<<'\n';
	
	return 0;
}
/*
20 20
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10
*/
/*
      ___           ___                            ___           ___           ___           ___           ___           ___             
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___   
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \  
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \ 
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /   
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/    
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\    
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/    
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/            
*/