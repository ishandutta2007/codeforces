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
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN][8];
bool ok[8][8];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (n==1) kill(0)
	if (n>=4) kill(-1) // :))
	for (int i=0; i<n; i++) for (int j=1; j<=m; j++){
		char ch;
		cin>>ch;
		A[j]|=((ch-'0')<<i);
	}
	for (int i=0; i<(1<<n); i++){
		for (int j=0; j<(1<<n); j++){
			ok[i][j]=1;
			for (int k=1; k<n; k++){
				int sum=(i>>k&1)+(i<<1>>k&1)+(j>>k&1)+(j<<1>>k&1);
				if (sum%2==0) ok[i][j]=0;
			}
		}
	}
	for (int i=1; i<=m; i++){
		for (int j=0; j<(1<<n); j++){
			dp[i][j]=inf;
			int cost=__builtin_popcount(A[i]^j);
			for (int jj=0; jj<(1<<n); jj++) if (ok[j][jj])
				dp[i][j]=min(dp[i][j], dp[i-1][jj] + cost);
		}
	}
	ans=inf;
	for (int j=0; j<(1<<n); j++) ans=min(ans, dp[m][j]);
	cout<<ans<<"\n";
	
	return 0;
}