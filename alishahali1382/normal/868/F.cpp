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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], cnt[MAXN];
ll dp[21][MAXN], cost;

void add(int x){
	cost+=cnt[x];
	cnt[x]++;
}
void rem(int x){
	cnt[x]--;
	cost-=cnt[x];
}

void divide(int k, int tl, int tr, int optl, int optr){
	if (tr<tl) return ;
	int mid=(tl+tr)>>1, opt=-1;
//	debug2(tl, tr)
//	debug(cost)
//	debug2(cnt[1], cnt[3])
//	debug2(optl, optr)
//	debug(mid)
	
	for (int i=tl; i<=mid; i++) add(A[i]);
//	debug(cost)
	for (int i=optl; i<=min(optr, mid); i++){
		rem(A[i]);
//		debug2(i, cost)
		if (dp[k-1][i]+cost<dp[k][mid]){
			dp[k][mid]=dp[k-1][i]+cost;
			opt=i;
		}
	}/*
	if (opt==-1){
		debug2(k, mid)
		assert(0);
	}*/
//	debug(dp[k][mid])
//	debug(opt)
//	cerr<<'\n'<<'\n'<<'\n';
	
	for (int i=min(optr, mid); i>=opt; i--) add(A[i]);
	divide(k, mid+1, tr, opt, optr);
	for (int i=tl; i<=mid; i++) rem(A[i]);
	for (int i=optl; i<opt; i++) add(A[i]);
	divide(k, tl, mid-1, optl, opt);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(dp, 63, sizeof(dp));
	dp[0][0]=0;
	cnt[0]=1;
	for (int i=1; i<=k; i++) divide(i, 1, n, 0, n);
	cout<<dp[k][n]<<'\n';
	
	return 0;
}
/*
7 1
1 1 3 3 3 2 1

*/