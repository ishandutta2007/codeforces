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
const int MAXN = 1510, LOG=20;

int n, s, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN], f[MAXN];
int dp[MAXN][MAXN], ps[MAXN];

bool check(int val){
	for (int i=1; i<=n; i++) ps[i]=ps[i-1] + (A[i]<=val);
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		dp[i][j]=dp[i-1][j];
		if (f[i]!=inf) dp[i][j]=max(dp[i][j], dp[f[i]-1][j-1] + ps[i]-ps[f[i]-1]);
	}
	
	return dp[n][m]>=k;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s>>m>>k;
	for (int i=1; i<=n; i++) cin>>A[i], f[i]=inf;
	while (s--){
		cin>>l>>r;
		for (int i=l; i<=r; i++) f[i]=min(f[i], l);
	}
	/*
	debug(check(3))
	debug(dp[n][m])
	return 0;*/
	
	int dwn=0, up=inf;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (check(mid)) up=mid;
		else dwn=mid;
	}
	if (up==inf) up=-1; 
	cout<<up<<'\n';
	
	return 0;
}