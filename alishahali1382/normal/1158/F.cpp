#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int N=3010, LG=11;

int n, m, k, u, v, x, y, t, a, b;
int A[N], ted[N];
ll F[N][N], inv[N];
int dp[N][N], pd[2][N][1<<LG];
ll tav[N], ans[N];
bool mark[N];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

inline void fix(int &x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod; 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<N; i++) tav[i]=tav[i-1]*2%mod;
	for (int i=0; i<N; i++) inv[i]=powmod(tav[i]-1, mod-2);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]--;
	if (k<=LG){
		pd[0][0][0]=1;
		for (int i=1; i<=n; i++){
			int x=(i&1);
			for (int j=0; j*k<=i; j++) for (int mask=0; mask<(1<<k)-1; mask++) pd[x][j][mask]=pd[x^1][j][mask];
			for (int j=0; j*k<=i; j++){
				for (int mask=0; mask<(1<<k)-1; mask++){
					fix(pd[x][j][mask|(1<<A[i])]+=pd[x^1][j][mask]);
				}
				fix(pd[x][j+1][0]+=pd[x][j][(1<<k)-1]);
				pd[x][j][(1<<k)-1]=0;
				ans[j]=(ans[j] + (pd[x][j][0]-pd[x^1][j][0])*tav[n-i])%mod;
			}
		}
		for (int j=0; j<=n; j++){
			int res=0;
			for (int mask=0; mask<(1<<k)-1; mask++) fix(res+=pd[n&1][j][mask]);
			fix(res-=(j==0));
			cout<<res<<" ";
		}
		cout<<"\n";
		return 0;
	}
	for (int l=1; l<=n; l++){
		ll val=1;
		int c0=k;
		fill(ted, ted+k, 0);
		for (int r=l; r<=n; r++){
			if (!ted[A[r]]) c0--;
			else val=val*inv[ted[A[r]]]%mod;
			ted[A[r]]++;
			val=val*(tav[ted[A[r]]]-1)%mod;
			if (!c0) F[l][r]=val*inv[ted[A[r]]]%mod;
		}
	}
	for (int r=1; r<=n; r++) for (int l=1; l<=r; l++) F[l][r]-=F[l+1][r];
	ans[0]=tav[n]-1;
	
	dp[0][0]=1;
	for (int i=1; i<=n; i++){
		for (int j=0; k*j<=i; j++) dp[i][j]=dp[i-1][j];
		for (int t=1; t<=i-k+1; t++){
			for (int j=0; k*j<=i; j++){
				dp[i][j]=(dp[i][j] + dp[t-1][j-1]*F[t][i])%mod;
			}
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j*k<=i; j++)
			ans[j]=(ans[j] + (dp[i][j]-dp[i-1][j])*tav[n-i])%mod;
	
	for (int i=0; i<=n; i++){
		ll res=(ans[i]-ans[i+1])%mod;
		if (res<0) res+=mod;
		cout<<res<<' ';
	}
	
	return 0;
}
/*
2 2
1 2

*/