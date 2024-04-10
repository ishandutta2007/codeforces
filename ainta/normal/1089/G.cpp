#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[7], S;
void Solve() {
	int i, j, res = 1e9;
	scanf("%d", &n);
	S = 0;
	for (i = 0; i < 7; i++) {
		scanf("%d", &w[i]);
		S += w[i];
	}
	for (i = 0; i < 7; i++) {
		int c = 0, t = 0;
		for (j = i; j < 7; j++) {
			c += w[j];
			t++;
			if (c >= n) {
				res = min(res, t);
			}
		}
		if (c < n) {
			t += (n - c - 1) / S * 7;
			c += (n - c - 1) / S * S;
		}
		for (j = 0; j < 7; j++) {
			c += w[j];
			t++;
			if (c >= n)res = min(res, t);
		}
	}
	printf("%d\n", res);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}