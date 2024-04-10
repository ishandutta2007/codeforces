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
const int MAXN = 51, LOG=20;

ll n, T, k, u, v, x, y, a, b=1, ans, id;
int t[MAXN], g[MAXN];
ll dp[3][51][2501];
ll ways[51][51][51][3];
ll dpp[51][51][2501];
int cnt[3];
vector<int> vec;

ll getways(int i, int j, int k){ return (ways[i][j][k][0] + ways[i][j][k][1] + ways[i][j][k][2])%mod;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>T;
	dp[0][0][0]=dp[1][0][0]=dp[2][0][0]=1;
	for (int i=0; i<n; i++){
		cin>>t[i]>>g[i];
		g[i]--;
		if (g[i]==1) vec.pb(t[i]);
		cnt[g[i]]++;
		for (int j=n; j; j--) for (int k=t[i]; k<=T; k++) dp[g[i]][j][k]=(dp[g[i]][j][k] + dp[g[i]][j-1][k-t[i]])%mod;
	}
	ways[0][0][1][2]=ways[0][1][0][1]=ways[1][0][0][0]=1;
	for (int i=0; i<=cnt[0]; i++) for (int j=0; j<=cnt[1]; j++) for (int k=0; k<=cnt[2]; k++) if (i+j+k>1) for (int last=0; last<3; last++){
		if (last==0 && i) ways[i][j][k][last]=i * (ways[i-1][j][k][1] + ways[i-1][j][k][2])%mod;
		if (last==1 && j) ways[i][j][k][last]=j * (ways[i][j-1][k][0] + ways[i][j-1][k][2])%mod;
		if (last==2 && k) ways[i][j][k][last]=k * (ways[i][j][k-1][0] + ways[i][j][k-1][1])%mod;
	}
	
	//debug(getways(5, 5, 5))
	
	for (int a=0; a<=cnt[0]; a++){
		for (int j=0; j<=T; j++) dpp[a][0][j]=dp[0][a][j];
		for (int x:vec) for (int b=cnt[1]; b; b--) for (int k=T; k>=0; k--) if (k>=x) dpp[a][b][k]=(dpp[a][b][k]+dpp[a][b-1][k-x])%mod;
	}/*
	debug(dpp[5][0][5])
	debug(dpp[5][2][7])
	debug(dpp[5][1][6])
	debug(dpp[5][5][10])
	*/
	for (int a=0; a<=cnt[0]; a++) for (int b=0; b<=cnt[1]; b++) for (int c=0; c<=cnt[2]; c++) for (int k=0; k<=T; k++) ans=(ans+(getways(a, b, c)*dpp[a][b][k]%mod)*dp[2][c][T-k])%mod;
	cout<<ans<<'\n';
	
	return 0;
}