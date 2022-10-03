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
const int N=45;

int n, m, k, u, v, x, y, t, a, b;
int S[N], f[N], nex[N][2];
ll dp[N][N], ans;
string s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	m=s.size();
	for (int i=1; i<=m; i++) S[i]=s[i-1]-'0';
	
	nex[0][S[1]]=1;
	for (int i=1; i<m; i++){
		nex[i][S[i+1]]=i+1;
		nex[i][S[i+1]^1]=nex[f[i]][S[i+1]^1];
		f[i+1]=nex[f[i]][S[i+1]];
	}
	nex[m][0]=nex[f[m]][0];
	nex[m][1]=nex[f[m]][1];
	
	//for (int i=0; i<=m; i++) cerr<<f[i]<<" \n"[i==m];
	
	for (int i=0; i<m; i++){
		memset(dp, 0, sizeof(dp));
		dp[0][i]=1;
		for (int j=0; j<n; j++) for (int k=0; k<m; k++){
			dp[j+1][nex[k][0]]+=dp[j][k];
			dp[j+1][nex[k][1]]+=dp[j][k];
		}
		ans+=dp[n][i];
	}
	cout<<(1ll<<n)-ans<<'\n';
	
	return 0;
}