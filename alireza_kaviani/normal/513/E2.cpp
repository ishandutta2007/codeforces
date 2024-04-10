#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 3e4+ 10;
const ll MAXK = 210;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , A[MAXN] , dp[MAXK][MAXN][3][3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j < 3 ; j++){
			for(int k = 0 ; k < 3 ; k += 2){
				dp[0][i][j][k] = -MOD;
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= k ; i++){
		for(int j = 0 ; j < 3 ; j++)
			for(int l = 0 ; l < 3 ; l++)
				dp[i][0][j][l] = -MOD;
		for(int j = 1 ; j <= n ; j++){
			for(int l = 0 ; l < 3 ; l++){
				int mx = -MOD;
				for(int m = 0 ; m < 3 ; m++)	mx = max(mx , dp[i - 1][j - 1][m][2 - l]);
				for(int m = 0 ; m < 3 ; m++){
					dp[i][j][l][m] = max(mx , dp[i][j - 1][l][m]) + (m + l - 2) * A[j];
//					cout << i << sep << j << sep << l << sep << m << sep << dp[i][j][l][m] << endl;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 3 ; j++){
			ans = max(ans , dp[k][i][j][1]);
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/