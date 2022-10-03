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
#define SZ(x) ((int)(x.size()))

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=3010, LOG=13;

ll n, m, k, u, v, x, y, t, a, b, ans;
vector<ll> A[MAXN];
ll dp[LOG][MAXN];

void add(ll *dp, int x, ll w){
	for (int i=k; i>=x; i--) dp[i]=max(dp[i], dp[i-x] + w);
}

void divide(int tl, int tr, int h){
	if (tr-tl==1){
		for (int i=0; i<SZ(A[tl]); i++) ans=max(ans, dp[h][k-i] + A[tl][i]);
		return ;
	}
	int mid=(tl+tr)>>1;
	memcpy(dp[h+1], dp[h], sizeof(dp[h+1]));
	for (int i=tl; i<mid; i++) add(dp[h+1], SZ(A[i])-1, A[i].back());
	divide(mid, tr, h+1);
	memcpy(dp[h+1], dp[h], sizeof(dp[h+1]));
	for (int i=mid; i<tr; i++) add(dp[h+1], SZ(A[i])-1, A[i].back());
	divide(tl, mid, h+1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>x;
		A[i].resize(x+1);
		for (int j=1; j<=x; j++) cin>>A[i][j], A[i][j]+=A[i][j-1];
		A[i].resize(min(k, x)+1);
	}
	memset(dp, -63, sizeof(dp));
	dp[0][0]=0;
	divide(1, n+1, 0);
	cout<<ans<<"\n";
	
	return 0;
}