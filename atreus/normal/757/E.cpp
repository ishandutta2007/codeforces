#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[maxn][22], p[maxn];
vector<int> v[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n = 20;
	for (int i = 0; i <= 1000 * 1000; i++){
		for (int j = 0; j < n; j++){
			if (i == 0)
				dp[i][j] = 1 + (j > 0);
			else{
				if (j == 0)
					dp[i][j] = dp[i-1][j];
				else{
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
					if (dp[i][j] >= mod)
						dp[i][j] -= mod;
				}
			}
		}
	}
	n = 1000*1000;
	for (int i = 2; i <= n; i++){
		if (p[i] == 0){
			for (int j = i; j <= n; j += i){
				p[j] |= 1;
				int x = j, y = 0;
				while (x % i == 0){
					y ++;
					x /= i;
				}
				v[j].push_back(y);
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int r, n;
		scanf("%d%d", &r, &n);
		int answer = 1;
		for (auto it : v[n])
			answer = 1ll * answer * dp[r][it] % mod;
		printf("%d\n", answer);
	}
}