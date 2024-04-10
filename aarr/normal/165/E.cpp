#include <iostream>
using namespace std;

const int M = 22;
const int N = 1000 * 1000 + 5, A = (1 << M) - 1;

int dp[A + 5];
int a[N];
int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[~a[i] & A] = i;
	}
	for (int i = A; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (!get(i, j) && dp[i + (1 << j)]) {
				dp[i] = dp[i + (1 << j)];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[a[i]]) {
			cout << a[dp[a[i]]];
		}
		else
			cout << -1;
		cout << " ";
	}
	return 0;
}