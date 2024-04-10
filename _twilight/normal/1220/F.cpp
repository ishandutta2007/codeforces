
#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n, tp;
int a[N];
int stk[N];
int dp[N];
int L[N], R[N]; 

void work(int *f) {
	tp = 0;
	for (int i = 0; i < n; i++) {
		int d = 0;
		while (tp && a[stk[tp]] > a[i]) {
			d = max(d, dp[stk[tp]]);
			tp--;
		}
		dp[i] = d = max(tp, d) + 1;
		stk[++tp] = i;
		f[i] = max((i) ? (f[i - 1]) : (0), d);
	}
}

int main() {
	scanf("%d", &n);
	int pos1 = -1, opt = 0, ans = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] == 1) {
			pos1 = i;
		}
	}
	rotate(a, a + pos1, a + n);
	work(L);
	reverse(a + 1, a + n);
	work(R);
	for (int i = 0; i < n; i++) {
		if (max(L[i], R[n - i - 1]) < ans) {
			ans = max(L[i], R[n - i - 1]);
			opt = i;
		}
	}
//	cerr << pos1 << " " << opt << '\n';
	opt = (opt + 1 + pos1) % n;
	printf("%d %d\n", ans, opt);
	return 0;
}