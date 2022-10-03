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
const int MAXN = 110, TOF=550000;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
int dp[MAXN][TOF];

ll solve(int i, ll j){
	if (j<TOF && dp[i][j]!=-1) return dp[i][j];
	if (i==0) return j;
	if (j<=1) return j;
	ll ans=solve(i-1, j)-solve(i-1, j/A[i]);
	if (j<TOF) dp[i][j]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	cin>>n>>k;
	for (int i=1; i<=k; i++) cin>>A[i];
	sort(A+1, A+k+1);
	if (A[1]==1) kill(0)
	cout<<solve(k, n);
	
	return 0;
}