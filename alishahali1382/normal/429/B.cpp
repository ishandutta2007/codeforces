#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1010;

int n, m, a, ans;
int A[MAXN][MAXN];
int dp1[MAXN][MAXN]; //  dp1.......dp2 
int dp2[MAXN][MAXN]; //    ....x....
int dp3[MAXN][MAXN]; //    .........
int dp4[MAXN][MAXN]; //  dp3.......dp4

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>A[i][j];
			dp1[i][j]=max(dp1[i-1][j], dp1[i][j-1]) + A[i][j];
		}
		for (int j=m; j; j--) dp2[i][j]=max(dp2[i-1][j], dp2[i][j+1]) + A[i][j];
	}
	for (int i=n; i; i--){
		for (int j=1; j<=m; j++) dp3[i][j]=max(dp3[i+1][j], dp3[i][j-1]) + A[i][j];
		for (int j=m; j; j--) dp4[i][j]=max(dp4[i+1][j], dp4[i][j+1]) + A[i][j];
	}
	for (int i=2; i<n; i++){
		for (int j=2; j<m; j++){
			//ans=max(ans, dp1[i][j]+dp2[i][j]+dp3[i][j]+dp4[i][j]-4*A[i][j]);
			ans=max(ans, max(dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j], dp1[i-1][j]+dp4[i+1][j]+dp2[i][j+1]+dp3[i][j-1]));
		}
	}
	/*
	cerr<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) cerr<<dp1[i][j]<<' ';cerr<<endl;
	}
	cerr<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) cerr<<dp2[i][j]<<' ';cerr<<endl;
	}
	cerr<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) cerr<<dp3[i][j]<<' ';cerr<<endl;
	}
	cerr<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) cerr<<dp4[i][j]<<' ';cerr<<endl;
	}*/
	
	cout<<ans<<endl;
	return 0;
}