#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e3 + 500;
vector <int> v[maxn];
long long dp[maxn][maxn];

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++){
		int p = i;
		for (int j = 1; j <= sqrt(p); j++){
			if (p % j == 0){
				v[p].push_back(j);
				if (j != sqrt(p))
					v[p].push_back(p / j);
			}
			p = i;
		}
	}
	v[1].push_back(1);
	for (int i = 1; i <= n; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k < v[j].size(); k++)
				dp[i][j] += dp[i - 1][v[j][k]] % mod;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		ans += dp[k][i];
		ans %= mod;
	}
	cout << ans << endl;
}