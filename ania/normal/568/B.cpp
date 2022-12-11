#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int mod = 1000000007;
const int maxn = 4040;

int qpow(int a, int n) {
	if (n==0) return 1;
	int b=qpow(a,n/2);
	b=1LL*b*b%mod;
	if (n&1) b=1LL*a*b%mod;
	return b;
}

int inv[maxn], fact[maxn], newt[maxn];
int dp[2][maxn];

int main() {
	int n;
	scanf("%d", &n);
	if (n==1) {
		printf("1\n");
		return 0;
	}
	fact[0]=1;
	FORI(i,n) fact[i]=1LL*fact[i-1]*i%mod;
	FOR(i,n+1) inv[i]=qpow(fact[i],mod-2);
	FOR(i,n+1) newt[i]=1LL*(1LL*fact[n]*inv[i]%mod)*inv[n-i]%mod;
	dp[0][1] = 1;
	int res = 1+n;
	for (int k = 2; k < n; k++) {
		FORI(i,k-1) {
			dp[1][i] = (1LL*dp[0][i]*i+dp[1][i])%mod;
			dp[1][i+1] += dp[0][i];
			if (dp[1][i+1] >= mod) dp[1][i+1]-=mod;
		}
		FORI(i,k) {
			dp[0][i] = dp[1][i];
			//printf("dp[%d][%d] = %d\n", k, i, dp[0][i]);
			res = (1LL*dp[1][i]*newt[k]+res) % mod;
			dp[1][i]=0;
		}
	}
	printf("%d\n", res);
	return 0;
}