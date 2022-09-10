#include <bits/stdc++.h>

using namespace std;

const int N = 100'007;
const long double INF = 1e9;
const long double eps = 1e-9;

int n, d;
int in[N];
long double log_in[N];

long double dp[N][10];
int prv[N][10];

int main() {
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		log_in[i] = log10(in[i]);
	}
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j < 10; ++j)
			dp[i][j] = -INF;
	dp[0][1] = 0.;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 10; ++j) {
			if(dp[i][j] < 0.)
				continue;
			
//			printf("%d %d -> %.10Lf\n", i, j, dp[i][j]);
			long double new_cand = dp[i][j] + log_in[i];
			int new_val = j * in[i] % 10;
			
			if(new_cand > dp[i + 1][new_val]) {
				dp[i + 1][new_val] = new_cand;
				prv[i + 1][new_val] = j;
			}
			
			if(dp[i][j] > dp[i + 1][j]) {
				dp[i + 1][j] = dp[i][j];
				prv[i + 1][j] = j;
			}
		}
	}
	
	if(d == 1 and dp[n][d] == 0.) {
		for(int i = 0; i < n; ++i)
			if(in[i] == 1) {
				printf("1\n%d\n", 1);
				exit(0);
			}
	}
	
	if(dp[n][d] < eps) {
		puts("-1");
		exit(0);
	}
	
	int cur = d;
	vector <int> ans;
	
	for(int i = n; i; --i) {
		int old_val = prv[i][cur];
		if(dp[i][cur] > dp[i - 1][old_val])
			ans.push_back(in[i - 1]);
		cur = old_val;
	}
	
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d ", v);
	puts("");
	return 0;
}