#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int inf = 2e8 + 5;

int n;
int *X, *Y;
int ans3 = 0, ans = 0;
int L = inf, Lid = -1, R = -inf, Rid = -1;
int U = inf, Uid = -1, D = -inf, Did = -1;

int calc(int i, int j, int k) {
	int l = min(min(X[i], X[j]), X[k]);
	int r = max(max(X[i], X[j]), X[k]);
	int u = min(min(Y[i], Y[j]), Y[k]);
	int d = max(max(Y[i], Y[j]), Y[k]);
	return r - l + d - u;
}

int main() {
	scanf("%d", &n);
	X = new int[(n + 1)];
	Y = new int[(n + 1)];
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		X[i] = x, Y[i] = y;
		if (x < L) L = x, Lid = i;
		if (x > R) R = x, Rid = i;
		if (y < U) U = y, Uid = i;
		if (y > D) D = y, Did = i;
	}
	for (int i = 1; i <= n; i++) {
		ans3 = max(ans3, calc(Lid, Rid, i));
		ans3 = max(ans3, calc(Lid, Uid, i));
		ans3 = max(ans3, calc(Lid, Did, i));
		ans3 = max(ans3, calc(Rid, Uid, i));
		ans3 = max(ans3, calc(Rid, Did, i));
		ans3 = max(ans3, calc(Uid, Did, i));
	}
	ans = R - L + D - U;
	ans <<= 1, ans3 <<= 1;
	printf("%d", ans3);
	for (int i = 4; i <= n; i++) {
		printf(" %d", ans);
	}
	return 0;
}