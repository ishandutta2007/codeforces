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
const int MAXN=100010, MAXM=800;

int n, m, k, u, v, x, y, t, a, b, ans, bad;
int dp[2][MAXM], ps[MAXM];
vector<int> vec[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>x>>y;
		if (x<=n-MAXM) bad++;
		else vec[y].pb(x);
	}
	memset(dp, 31, sizeof(dp));
	dp[n&1^1][0]=0;
	for (int i=n; i; i--){
		int I=(i&1);
		memset(ps, 0, sizeof(ps));
		for (int x:vec[i]) ps[n-x]++;
		for (int i=min(MAXM-1, n); i; i--) ps[i-1]+=ps[i];
		dp[I][0]=dp[I^1][0] + ps[0]*3;
		for (int k=1; k<min(MAXM, n+1); k++){
			dp[I][0]=min(dp[I][0], dp[I^1][k-1] + 2+k*(k+1)/2 + 3*ps[k]);
		}
		for (int j=1; j<min(MAXM, n+1); j++){
			dp[I][j]=min(dp[I^1][j-1] + 3*ps[j], dp[I][0]);
		}
	}
	ans=dp[1][0];
	cout<<ans+3*bad<<"\n";
	
	return 0;
}
/*
7 11
2 2
3 1
4 3
5 1
5 2
5 5
6 4
7 2
7 3
7 4
7 5

*/