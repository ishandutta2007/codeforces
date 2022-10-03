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

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN];
ll dp[101][MAXN];

ll cost(int l, int r){ // (l, r]
	return B[r]*(r-l);
}

void divide(int k, int l, int r, int optl, int optr){
	if (r<l) return ;
	int mid=(l+r)>>1, opt;
	for (int j=optl; j<=min(optr, mid); j++) if (dp[k-1][j]+cost(j, mid)<dp[k][mid]){
		dp[k][mid]=dp[k-1][j]+cost(j, mid);
		opt=j;
	}
	divide(k, l, mid-1, optl, opt);
	divide(k, mid+1, r, opt, optr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	k=min(k, m);
	for (int i=2; i<=n; i++) cin>>A[i], A[i]+=A[i-1];
	for (int i=1; i<=m; i++){
		cin>>x>>t;
		x=A[x];
		B[i]=t-x;
		//debug2(x, t)
		ans-=B[i];
	}
	sort(B+1, B+m+1);
	//reverse(B+1, B+m+1);
	memset(dp, 31, sizeof(dp));
	dp[0][0]=0;
	for (int i=1; i<=k; i++) divide(i, 1, m, 0, m);
	cout<<dp[k][m]+ans<<'\n';
	
	return 0;
}