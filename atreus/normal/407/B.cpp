#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e3 + 100;
ll dp[maxn][5], p[maxn];

int main (){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i][0] = (dp[i - 1][1] + 1) % mod;
		dp[i][1] = (dp[i][0] + 1 - dp[p[i]][0] + dp[i][0] + mod) % mod;
	}
	cout << (dp[n][1] + 1) % mod << endl;
}