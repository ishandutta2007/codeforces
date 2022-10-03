#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 55;

ll n, m, k, ans, x, q;
ll dp[MAXN][MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<=30; i++){
		for (int k=1; k<=50; k++){
			dp[i][0][k]=dp[0][i][k]=inf;
		}
	}
	for (int i=1; i<=30; i++){
		for (int j=1; j<=30; j++){
			for (int k=1; k<=50; k++){
				if (k>i*j) dp[i][j][k]=inf;
				else if (k==i*j) dp[i][j][k]=0;
				else{
					dp[i][j][k]=inf;
					for (int cut=1; cut<j; cut++){
						for (int kk=0; kk<=k; kk++) dp[i][j][k]=min(dp[i][j][k], i*i+dp[i][cut][kk]+dp[i][j-cut][k-kk]);
					}
					for (int cut=1; cut<i; cut++){
						for (int kk=0; kk<=k; kk++) dp[i][j][k]=min(dp[i][j][k], j*j+dp[cut][j][kk]+dp[i-cut][j][k-kk]);
					}
				}
			}
		}
	}
	cin>>q;
	while (q--){
		cin>>n>>m>>k;
		cout<<dp[n][m][k]<<endl;
	}
	return 0;
}