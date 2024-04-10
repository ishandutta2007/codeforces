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
const int N=42;

int n, m, k, u, v, x, y, t, a, b, ans;
char A[N][N], B[N][N];
int dp[N+1][N+1][N+1][N+1];
bool mark[N*N/4+2];

int Solve(){
	for (int l1=N-1; l1; l1--) for (int l2=l1; l2<N; l2++)
		for (int r1=N-1; r1; r1--) for (int r2=r1; r2<N; r2++){
			memset(mark, 0, sizeof(mark));
			for (int l3=l1; l3<=l2; l3++) for (int r3=r1; r3<=r2; r3++){
				if (B[l3][r3]=='R') mark[dp[l1][r1][l3-1][r2]^dp[l3+1][r1][l2][r2]]=1;
				if (B[l3][r3]=='L') mark[dp[l1][r1][l2][r3-1]^dp[l1][r3+1][l2][r2]]=1;
				if (B[l3][r3]=='X') mark[dp[l1][r1][l3-1][r3-1]^dp[l3+1][r1][l2][r3-1]^dp[l1][r3+1][l3-1][r2]^dp[l3+1][r3+1][l2][r2]]=1;
			}
			while (mark[dp[l1][r1][l2][r2]]) dp[l1][r1][l2][r2]++;
		}
	return dp[1][1][N-1][N-1];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>A[i][j];
	n=m=max(n, m);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if ((i+j)%2==0){
		B[n-1+(i-j)/2+1][(i+j)/2+1]=A[i][j];
	}
	ans=Solve();
	debug(ans)
	debug(B[1][1])
	debug(B[1][2])
	debug(B[2][1])
	debug(B[2][2])
	debug(dp[1][1][2][1])
	
	memset(B, 0, sizeof(B));
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if ((i+j)%2==1){
		B[n-1+(i-j-1)/2+1][(i+j-1)/2+1]=A[i][j];
	}
	ans^=Solve();
	debug(ans)
	
	
	if (ans) cout<<"WIN\n";
	else cout<<"LOSE\n";
	
	return 0;
}
/*
2 2
XL
XX

*/