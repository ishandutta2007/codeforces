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
const ll INF=10000000000000010LL;
const int mod=998244353;
const int MAXN=5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll C[MAXN][MAXN], F[MAXN];
ll ps[MAXN], dp[MAXN][MAXN];
int A[MAXN], L[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	for (int i=0; i<MAXN; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++){
		for (int j=1; j<i; j++) if (A[i]>=2*A[j]) L[i]=j;
	}
	dp[0][0]=1;
	for (int i=1; i<=n; i++){
		ps[0]=dp[i-1][0];
		for (int j=1; j<=n; j++) ps[j]=(ps[j-1] + dp[i-1][j])%mod;
		for (int j=1; j<=n; j++){
			dp[i][j]=(dp[i-1][j]*(L[j]-i+2) + ps[L[j]])%mod;
		}
	}
	cout<<dp[n][n]<<"\n";
	
	
	return 0;
}