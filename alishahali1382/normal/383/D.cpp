#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int mod=1000 * 1000 * 1000 + 7;
const int MAXN=1010;

int n, a;
int dp[MAXN][20010];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	dp[0][10000]=1;
	for (int i=1; i<=n; i++){
		cin>>a;
		dp[i][10000]=1;
		for (int j=0; j<=20000-a; j++){
			dp[i][j]+=dp[i-1][j+a];
		}
		for (int j=a; j<=20000; j++){
			dp[i][j]=(dp[i][j] + dp[i-1][j-a]) % mod;
		}
	}
	ll ans=0;
	for (int i=1; i<=n; i++){
		ans=(ans + dp[i][10000] - 1)%mod;
		/*
		for (int j=10000-5; j<=10005; j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;*/
	}
	cout<<ans<<endl;
	return 0;
}