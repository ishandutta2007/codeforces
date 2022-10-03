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
const int MAXN = 55, LOG=20;

int n, m, k, h, x, y, t, a, b, ans, bad;
int L[MAXN], R[MAXN], X[MAXN], C[MAXN];
int dp[MAXN][MAXN][MAXN];

int calc(int l, int r, int pos, int val){
	int res=0;
	for (int i=1; i<=m; i++) res+=(X[i]<val && l<=L[i] && L[i]<=pos && pos<=R[i] && R[i]<=r)*C[i];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>h>>m;
	for (int i=1; i<=m; i++) cin>>L[i]>>R[i]>>X[i]>>C[i];
	for (int len=0; len<=n; len++) for (int i=1; i+len<=n; i++) for (int k=1; k<=h; k++){
		int j=i+len;
		dp[i][j][k]=dp[i][j][k-1];
		for (int pos=i; pos<=j; pos++) dp[i][j][k]=max(dp[i][j][k], dp[i][pos-1][k] + dp[pos+1][j][k] + k*k - calc(i, j, pos, k));
	}
	cout<<dp[1][n][h]<<'\n';
	
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