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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
ld dp[MAXN][MAXN], pd[MAXN][MAXN], ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dp[i][j]=(A[i]<A[j]);
	while (m--){
		cin>>x>>y;
		for (int i=1; i<=n; i++){
			pd[i][x]=(dp[i][x] + dp[i][y])*.5;
			pd[x][i]=(dp[x][i] + dp[y][i])*.5;
			pd[i][y]=(dp[i][x] + dp[i][y])*.5;
			pd[y][i]=(dp[x][i] + dp[y][i])*.5;
		}
		for (int i=1; i<=n; i++){
			dp[i][x]=pd[i][x];
			dp[i][y]=pd[i][y];
			dp[x][i]=pd[x][i];
			dp[y][i]=pd[y][i];
		}
		dp[x][y]=dp[y][x]=.5;
		dp[x][x]=dp[y][y]=0;
	}
	for (int i=1; i<=n; i++) for (int j=1; j<i; j++) ans+=dp[i][j];
	cout<<setprecision(12)<<fixed<<ans<<'\n';
	
	return 0;
}