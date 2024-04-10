#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

const int maxn = 5005;
long long b[maxn], a[maxn];
long long dp[5][maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	long long k = 1000000000000000000;
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == 1 && i == j)
				dp[i][j] = max(a[i] - b[j], 0ll);
			else if (i == 1)
				dp[i][j] = min(dp[i][j - 1], abs(a[i] - b[j]));
			else if (j == 1){
				if (i % 3 != 0)
					dp[i % 3][j] = dp[(i % 3) - 1][j] + abs(a[i] - b[j]);
				else
					dp[i % 3][j] = dp[2][j] + abs(a[i] - b[j]);
			}
			else if (i % 3 != 0)
				dp[i % 3][j] = min(dp[(i % 3) - 1][j] + abs(a[i] - b[j]), dp[i % 3][j - 1]);
			else if (i % 3 == 0)
				dp[i % 3][j] = min(dp[2][j] + abs(a[i] - b[j]), dp[i % 3][j - 1]);
//			cout << dp[i % 3][j] << " ";
			if (i == n)
				k = min(k, dp[i % 3][j]);
		}
//		cout << endl;
	}
	cout << k << endl;
}