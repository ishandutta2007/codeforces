#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> X(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	sort(X.begin(), X.end());
	int z = N / K;
	int B = N % K;
	int A = K - B;

	//cerr << N << " " << z * A + (z + 1)*B << endl;
	int INF = (int)1 << 60;
	vector<vector<int> > dp(A + 1, vector<int>(B + 1, INF));

	dp[0][0] = 0;
	for (int a = 0; a <= A; a++) {
		for (int b = 0; b <= B; b++) {
			if (dp[a][b] < INF) {
				int cur = z * a + (z + 1)*b;
				if (a < A)dp[a + 1][b] = min(dp[a + 1][b], dp[a][b] + X[cur + z - 1] - X[cur]);
				if (b < B)dp[a][b + 1] = min(dp[a][b + 1], dp[a][b] + X[cur + z] - X[cur]);


			}
		}
	}
	cout << dp[A][B] << endl;
}