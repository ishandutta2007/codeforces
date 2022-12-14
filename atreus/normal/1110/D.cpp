/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
int a[maxn];
int dp[2][10][10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[x] ++;
	}
	if (m <= 2)
		return cout << a[1] / 3 + a[2] / 3 << endl, 0;
	int answer = 0;
	for (int i = 1; i <= m; i++){
		if (a[i] >= 9){
			int k = a[i] % 3;
			k += 6;
			answer += (a[i] - k) / 3;
			a[i] = k;
		}
	}
	for (int i = 0; i <= a[1]; i++)
		for (int j = 0; j <= a[2]; j++)
			dp[0][i][j] = (a[1] - i) / 3 + (a[2] - j) / 3;
	int p = 0;
	for (int x = 3; x <= m; x++){
		p ^= 1;
		for (int i = 0; i <= a[x - 1]; i++){
			for (int j = 0; j <= a[x]; j++){
				dp[p][i][j] = 0;
				for (int k = 0; k <= min(2, min(a[x] - j, min(a[x - 1] - i, a[x - 2]))); k++){
					dp[p][i][j] = max(dp[p][i][j], k + (a[x] - k - j) / 3 + dp[p ^ 1][k][i + k]);
				}
			}
		}
	}
	cout << answer + dp[p][0][0] << endl;
}