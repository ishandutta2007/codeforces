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
const int MAXN = 5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
ll A[MAXN];
ll cnt[MAXN];
int dp[MAXN][2*MAXN];
ll dp2[2][2*MAXN];
ll ans[MAXN*2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	cnt[1]=1;
	for (ll i=1; i<n; i++){
		cin>>A[i];
		cnt[i+1]=cnt[i]*A[i]%mod;
	}
	dp[n][0]=1;
	for (int i=n-1; i; i--){
		dp[i][0]=1;
		for (int j=1; j<n; j++) dp[i][j]=dp[i+1][j-1]*A[i]%mod;
	}
	for (int j=0; j<=2*n-2; j++) ans[j]=dp2[0][j]=dp[1][j];
	//for (int j=1; j<=2*n-2; j++) ans[j]=dp2[1][j];
	
	for (int i=2; i<=n; i++){
		dp2[1][0]=1;
		dp2[1][1]=1+A[i];
		for (int j=2; j<=2*n-2; j++) dp2[1][j]=(1ll*dp[i][j]+dp2[0][j-1]-dp[i][j-2])%mod;
		
		for (int j=1; j<=2*n-2; j++) ans[j]=(ans[j] + dp2[1][j]*cnt[i])%mod;
		for (int j=0; j<=2*n-2; j++){
			dp2[0][j]=dp2[1][j];
			dp2[1][j]=0;
		}
	}
		
	for (int i=1; i<=2*n-2; i++){
		if (ans[i]<0) ans[i]+=mod;
		ans[i]=(ans[i]*(mod+1)/2)%mod;
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
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