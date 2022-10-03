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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 105, K=1000;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int F1[MAXN][MAXN][2*MAXN];
int F2[MAXN][MAXN][2*MAXN];
int F3[MAXN][MAXN][2*MAXN];
ld dp[K+1][MAXN][MAXN];

int C(int x){
	return x*(x+1)/2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	k=min(k, K);
	for (int i=0; i<n; i++) cin>>A[i];
	
	for (int l=0; l<n; l++) for (int r=l; r<n; r++){
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++){
			bool ii=(l<=i && i<=r);
			bool jj=(l<=j && j<=r);
			if (ii && !jj) F1[i][j][l+r]++;
			if (!ii && jj) F2[i][j][l+r]++;
			if (ii && jj) F3[i][j][l+r]++;
		}		
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<i; j++) dp[0][i][j]=1;
	for (int x=1; x<=k; x++){
		for (int i=0; i<n; i++) for (int j=0; j<n; j++){
			if (i>=j) continue ;
			dp[x][i][j]=(C(i) + C(j-i-1) + C(n-j-1))*dp[x-1][i][j];
			for (int cent=0; cent<=2*n-2; cent++){
				if (cent-i>=0) dp[x][i][j]+=F1[i][j][cent]*dp[x-1][cent-i][j];
				if (cent-j>=0) dp[x][i][j]+=F2[i][j][cent]*dp[x-1][i][cent-j];
				if (cent-max(i, j)>=0) dp[x][i][j]+=F3[i][j][cent]*dp[x-1][cent-i][cent-j];
			}
			dp[x][i][j]/=C(n);
			dp[x][j][i]=1.-dp[x][i][j];
		}
	}
	ld ans=0;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (A[i]<A[j]) ans+=dp[k][i][j];
	cout<<setprecision(12)<<fixed<<ans<<'\n';
	
	return 0;
}