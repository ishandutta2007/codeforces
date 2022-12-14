#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 500 + 10;

int dp[maxn][maxn], good[maxn][maxn];
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(dp, 63, sizeof dp);
	for (int len = 1; len <= n; len ++){
		for (int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			if (l == r){
				good[l][r] = a[l];
				dp[l][r] = 1;
				continue;
			}
			for (int m = l; m < r; m++){
				if (good[l][m] != 0 and good[l][m] == good[m+1][r]){
					good[l][r] = good[l][m] + 1;
					break;
				}
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r]);
			}
			if (good[l][r] != 0)
				dp[l][r] = 1;
		}
	}
	cout << dp[1][n] << endl;
}