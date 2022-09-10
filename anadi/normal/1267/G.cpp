#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>

const int N = 107;
const int S = 10007;

int n, x;
int in[N];

int allSum = 0;
T ans, c[N];
T dp[10][N][S];

void update(int lvl, int from, int to, int s, int e){
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= allSum; ++j)
			dp[lvl][i][j] = dp[lvl - 1][i][j];
	
	for(int i = s; i <= e; ++i){
		for(int j = n; j >= 0; --j)
			for(int k = allSum - in[e]; k >= 0; --k)
				dp[lvl][j + 1][k + in[i]] += dp[lvl][j][k] * (j + 1) / (T)(n - j);
	}
}

void go(int lvl, int from, int to){
	if(from == to){
//		printf("%d %d %d\n", lvl, from, to);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= allSum; ++j){
				if((n + i) * x < 2 * j)
					continue;
				
//				if(dp[lvl - 1][i][j] > 0.000 && (n + i + 1) * x < 2 * (j + in[from]))
//					printf("dp[%d][%d] = %.5Lf, c[%d] = %.5Lf\n", i, j, dp[lvl - 1][i][j], n - i, c[n - i]);

				if((n + i + 1) * x < 2 * (j + in[from]))
					ans += dp[lvl - 1][i][j] * (c[n - i] + j) / (T)(n - i);
			}

		return;
	}
	
	int mid = (from + to) / 2;
	update(lvl, from, to, mid + 1, to);
	go(lvl + 1, from, mid);
	
	update(lvl, from, to, from, mid);
	go(lvl + 1, mid + 1, to);	
}

int main(){
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		allSum += in[i];
	}

	sort(in + 1, in + n + 1);
	if(in[n] == x){
		printf("%.10lf\n", (T)n * x);
		exit(0);
	}
	
	if(n == 1){
		printf("%.10lf\n", (T)x);
		exit(0);
	}
	
	for(int i = 1; i <= n; ++i)
		c[i] = c[i - 1] + (T)n / (T)(n - i + 1) * (T)x / 2.0 + (T)x / 2.0;

	dp[0][0][0] = 1.0;
	go(1, 1, n);
	printf("%.15lf\n", ans);
	return 0;
}