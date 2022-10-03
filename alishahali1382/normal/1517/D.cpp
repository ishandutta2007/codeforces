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
const int N=505;

int n, m, k, u, v, x, y, t, a, b;
int A[N][N], B[N][N];
int dp[11][N][N];

inline void upd(int &x, int y){ if (y<x) x=y;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	if (k&1){
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cout<<-1<<" \n"[j==m];
		return 0;
	}
	k>>=1;
	for (int i=1; i<=n; i++) for (int j=1; j<m; j++) cin>>A[i][j];
	for (int i=1; i<n; i++) for (int j=1; j<=m; j++) cin>>B[i][j];
	for (int t=1; t<=k; t++){
		memset(dp[t], 63, sizeof(dp[t]));
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
			if (j<m) upd(dp[t][i][j], dp[t-1][i][j+1]+A[i][j]);
			if (i<n) upd(dp[t][i][j], dp[t-1][i+1][j]+B[i][j]);
			if (1<j) upd(dp[t][i][j], dp[t-1][i][j-1]+A[i][j-1]);
			if (1<i) upd(dp[t][i][j], dp[t-1][i-1][j]+B[i-1][j]);
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cout<<2*dp[k][i][j]<<" \n"[j==m];	
	
	return 0;
}