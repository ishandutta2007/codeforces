#include <bits/stdc++.h> 

using namespace std;

const int M = 1550;
const int N = 1e5 + 10;

int n, k, x, a[2][M];

int main (int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; ++i) {
		int z; scanf("%d", &z);
		++a[0][z];
	}
	int pre = 0, now = 1;
	// for (int i = 0; i <= 20; ++i) {
	// 	cout << i << ": " << a[pre][i] << endl;
	// }
	for (int i = 1; i <= k; ++i) {
		int f = 0;
		memset(a[now], 0, sizeof a[now]);
		for (int j = 0; j <= 1500; ++j) {
			int cur = a[pre][j];
			a[now][j ^ x] += (cur + 1 - f)/2;
			a[now][j] += (cur + f)/2;
			f += cur, f &= 1;
		}
		swap(pre, now);
	}
	// for (int i = 0; i <= 20; ++i) {
	// 	cout << i << ": " << a[pre][i] << endl;
	// }
	int mini, maxi;
	for (int i = 0; i <= 1500; ++i) {
		if (a[pre][i] != 0) {
			mini = i;
			break;
		}
	}
	for (int i = 1500; i >= 0; --i) {
		if (a[pre][i] != 0) {
			maxi = i;
			break;
		}
	}
	printf("%d %d\n", maxi, mini);
    return 0;
}