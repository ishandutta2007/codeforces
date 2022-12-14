/**
 *    author:  Atrues
 *    created: 24.01.2019 18:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
int dp[300 + 10][maxn];
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= 300; i++){
		for (int j = n; j >= 1; j--){
			int nex = j + i + a[j];
			if (nex > n)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i][nex] + 1;
		}
	}
	int q;
	cin >> q;
	while (q --){
		int p, k;
		cin >> p >> k;
		if (k <= 300){
			cout << dp[k][p] << '\n';
			continue;
		}
		int cnt = 0;
		while (p <= n){
			p = p + a[p] + k;
			cnt ++;
		}
		cout << cnt << '\n';
	}
}