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
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ld A[MAXN], B[MAXN], C[MAXN];
ld dp[51][MAXN];

inline ld Cost(int l, int r){ // (l, r]
	ld tmp=C[r]-C[l];
	tmp-=A[l]*(B[r]-B[l]);
	return tmp+r-l;
}

void divide(int j, int tl, int tr, int optl, int optr){
	if (tr<tl) return ;
	//cerr<<"divide "<<tl<<' '<<tr<<"  "<<optl<<' '<<optr<<endl;
	int mid=(tl+tr)>>1, opt;
	for (int i=optl; i<=min(mid, optr); i++){
		ld w=dp[j-1][i]+Cost(i, mid);
		if (w<dp[j][mid]){
			dp[j][mid]=w;
			opt=i;
		}
	}
	//debug2(opt, dp[j][mid])
	divide(j, tl, mid-1, optl, opt);
	divide(j, mid+1, tr, opt, optr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		C[i]=C[i-1]+A[i-1]/A[i];
		B[i]=B[i-1]+1/A[i];
		A[i]+=A[i-1];
	}
	//debug(Cost(1, 4))
	for (int i=0; i<=k; i++) fill(dp[i]+1, dp[i]+n+1, 1e18);
	for (int i=1; i<=k; i++) divide(i, 1, n, 0, n);
	cout<<setprecision(12)<<fixed<<dp[k][n]<<'\n';
	
	return 0;
}
/*
3 1
3 5 7

*/