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
const int MAXN = 510, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, mod;
int A[MAXN];
ll dp[MAXN][MAXN];
char ch;

ll C2(ll n){
	return n*(n-1)/2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>mod;
	for (int i=1; i<=m; i++) for (int j=1; j<=n; j++){
		cin>>ch;
		A[j]+=(ch=='1');
	}
	for (int i=1; i<=n; i++){
		if (A[i]==1) a++;
		if (A[i]==2) b++;
	}
	dp[a][b]=1;
	for (int j=0; j<=n; j++) for (int i=0; i<=n; i+=2) if (i+2*j>2*m){
		if (i>=2) dp[i][j]+=C2(n-i-j+2)*dp[i-2][j];
		if (j>=1) dp[i][j]+=i*(n-i-j+1)*dp[i][j-1];
		if (j>=2) dp[i][j]+=C2(i+2)*dp[i+2][j-2];
		dp[i][j]%=mod;
		//debug2(i, j)
	}
	cout<<dp[0][n]<<'\n';
	/*
	debug(dp[2][0])
	debug(dp[0][2])
	debug(dp[2][1])
	debug(dp[0][3])*/
	
	return 0;
}
/*
5 0 13
5 0 1000
*/