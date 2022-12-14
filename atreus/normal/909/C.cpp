#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5e3 + 100;
int dp[maxn][maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		if (c == 'f')
			for (int j = 1; j < maxn - 2; j++){
				dp[i + 1][j] = dp[i][j - 1] % mod;
//				cout << i + 1 << " " << j << " " << dp[i + 1][j] << endl;
			}
		if (c == 's')
			for (int j = maxn - 2; j >= 0; j--){
				dp[i + 1][j] = (dp[i][j] + dp[i + 1][j + 1]) % mod;
	//			cout << i + 1 << " " << j << " " << dp[i + 1][j] << endl;
			}
	}
	long long ans = 0;
	for (int i = 0; i < maxn; i++)
		ans = (ans + dp[n - 1][i]) % mod;
	cout << ans << endl;
}