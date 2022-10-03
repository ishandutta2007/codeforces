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
const int MAXN = 4005, K=803;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
int dp[K][MAXN];

int cost(int l, int r){ // (l, r]
	return A[r][r]-A[l][r]-A[r][l]+A[l][l];
}

void divide(int k, int tl, int tr, int optl, int optr){
	if (tr-tl<=5 || optl==optr){
		for (int i=tl; i<=tr; i++)
			for (int j=optl; j<=optr; j++)
				dp[k][i]=min(dp[k][i], dp[k-1][j] + cost(j, i));
		return ;
	}
	int mid=(tl+tr)>>1, opt=optl;
	for (int i=optl; i<=optr; i++){
		int tmp=dp[k-1][i] + cost(i, mid);
		if (dp[k][mid]>tmp){
			dp[k][mid]=tmp;
			opt=i;
		}
	}
	divide(k, tl, mid-1, optl, opt);
	divide(k, mid+1, tr, opt, optr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		char ch;
		cin>>ch;
		A[i][j]=ch-'0' + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
	}
	memset(dp, 31, sizeof(dp));
	dp[0][0]=0;
	for (int i=1; i<=k; i++) divide(i, 1, n, 0, n);
	cout<<dp[k][n]/2<<'\n';
	
	return 0;
}