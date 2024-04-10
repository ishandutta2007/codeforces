#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 5e3 + 100;
long long a[maxn], dp[maxn][maxn];
int main (){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = n; i >= 1; i--){
		if (i >= m)
			a[i] -= a[i - m];
		else
			a[i] = 0;
	}
	for (int i = m; i <= n; i++){
		for (int j = 1; j <= k; j++){
			dp[i][j] = max (dp[i - 1][j], dp[i - m][j - 1] + a[i]);
		}
	}
	cout << dp[n][k] << endl;
}