#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PII pair <int, int>

const int N = 200;
const int T = 3 * N + 9;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
double val[N];
double a[N][N];
double dp[N][N];
double pro[N][N];
int from[N], to[N];

int main(){
	scanf("%d", &n);
	n = 1 << n;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%lf", &pro[i][j]),
			pro[i][j] /= 100;
		
	int k = n;
	for(int i = k; i < k + n; ++i)
		val[i] = 0.5,
		from[i] = to[i] = i - k + 1,
		a[i][i - k + 1] = 1.0;

	for(int i = k - 1; i >= 1; --i)
		from[i] = from[2 * i], to[i] = to[2 * i + 1];
	
	for(int i = k - 1; i >= 1; --i){
		val[i] = val[2 * i] + val[2 * i + 1];
		for(int j = from[2 * i]; j <= to[2 * i]; ++j){
			for(int ii = from[2 * i + 1]; ii <= to[2 * i + 1]; ++ii)
				a[i][j] += a[2 * i + 1][ii] * pro[j][ii];
			a[i][j] *= a[2 * i][j];

			for(int ii = from[2 * i + 1]; ii <= to[2 * i + 1]; ++ii)
				dp[i][j] = max(dp[i][j], dp[2 * i + 1][ii]);
			dp[i][j] += dp[2 * i][j] + a[i][j] * val[i];
		}

		for(int j = from[2 * i + 1]; j <= to[2 * i + 1]; ++j){
			for(int ii = from[2 * i]; ii <= to[2 * i]; ++ii)
				a[i][j] += a[2 * i][ii] * pro[j][ii];
			a[i][j] *= a[2 * i + 1][j];

			for(int ii = from[2 * i]; ii <= to[2 * i]; ++ii)
				dp[i][j] = max(dp[i][j], dp[2 * i][ii]);
			dp[i][j] += dp[2 * i + 1][j] + a[i][j] * val[i];
		}
	}
	
	double res = 0.0;
	for(int i = 1; i <= n; ++i)
		res = max(res, dp[1][i]);
	printf("%.10lf\n", res);
	return 0;
}