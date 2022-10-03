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
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, p, k, u, v, x, y, t, a, b, ans;
int A[MAXN], ind[MAXN];
ll dp[MAXN][1<<7];
ll S[MAXN][7];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p>>k;
	for (int i=1; i<=n; i++) cin>>A[i], ind[i]=i;
	for (int i=1; i<=n; i++) for (int j=0; j<p; j++) cin>>S[i][j];
	sort(ind+1, ind+n+1, [](int i, int j){
		return A[i]>A[j];
	});
	
	memset(dp, -31, sizeof(dp));
	dp[0][0]=0;
	for (int i=1; i<=n; i++) for (int mask=0; mask<(1<<p); mask++){
		for (int j=0; j<p; j++) if (mask&(1<<j)) dp[i][mask]=max(dp[i][mask], dp[i-1][mask^(1<<j)] + S[ind[i]][j]);
		int tmp=(i-1-__builtin_popcount(mask)<k);
		dp[i][mask]=max(dp[i][mask], dp[i-1][mask] + tmp*A[ind[i]]);
	}
	ans=dp[n][(1<<p)-1];
	cout<<ans<<'\n';
	
	return 0;
}
/*
3 2 1
564 500 498
232323 1
100002 3
422332 2

*/