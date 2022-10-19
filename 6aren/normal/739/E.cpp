#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
const int REP = 60;


double pa[N], pb[N], pab[N];
int n, a, b;

double dp[N][N];
int op[N][N];

int solve(double cost) {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= a; j++) {
			dp[i][j] = dp[i - 1][j];
			op[i][j] = op[i - 1][j];

			if (j > 0 && dp[i][j] < dp[i - 1][j - 1] + pa[i]) {
				dp[i][j] = dp[i - 1][j - 1] + pa[i];
				op[i][j] = op[i - 1][j - 1];
			}

			if (dp[i][j] < dp[i - 1][j] + pb[i] - cost) {
				dp[i][j] = dp[i - 1][j] + pb[i] - cost;
				op[i][j] = op[i - 1][j] + 1;
 			}

 			if (j > 0 && dp[i][j] < dp[i - 1][j - 1] + pab[i] - cost) {
 				dp[i][j] = dp[i - 1][j - 1] + pab[i] - cost;
 				op[i][j] = op[i - 1][j - 1] + 1;
 			} 
		}
 	}

 	return op[n][a];

}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> pa[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> pb[i];
	}
	for (int i = 1; i <= n; i++) {
		pab[i] = pa[i] + pb[i] - pa[i] * pb[i];
	}

	double l = 0, r = 2;
	for (int rep = 0; rep < REP; rep++) {
		double mid = (l + r) / 2;
		if (solve(mid) <= b)
			r = mid;
		else 
			l = mid;
	}

	int foo = solve(r);

	cout << setprecision(10) << fixed << dp[n][a] + r * b << endl; 

	return 0;
}