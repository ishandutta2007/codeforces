#include <bits/stdc++.h>
const int N = 1005;
int n, m, tot, cnt[N];
char s[N];
const double alpha = 10;
double S(double x) { return 1/(1+exp(-alpha * (x - 0.5))); }
void read() { scanf("%s", s); }
void guess(int c) {
	printf("%d\n", c); fflush(stdout);
}
void check() {
	int ans; scanf("%d", &ans);
	for (int i = 0; i < n; i++)
		if (s[i] - '0' == ans) cnt[i]++;
}
int main() {
	// freopen("ques.in", "r", stdin);
	// for (int i = 0; i <= 50; i++) printf("[%.3lf]%.6lf\n", i / 50.0, S(i / 50.0));
	
	srand(time(0));
	scanf("%d%d", &n, &m);
	for (tot = 0; tot < m; tot++) {
		read();
		double p = 0, q = 0;
		if (tot) {
			for (int i = 0; i < n; i++) {
				double x = 1.0 * cnt[i] / tot, y = fabs(pow(2*x, 40));
				if (s[i] == '0') p += x * y;
				else p += (1 - x) * y;
				q += y;
			}
		}
		if (q > 1e-12) p /= q;

		// if (tot) for (int i = 0; i < n; i++) printf("[%d]%.4lf", i, 1.0 * cnt[i] / tot); puts("");
		// printf("[%.4lf]=>[%.4lf]\n", p, S(p));

		guess(1.0 * rand() / RAND_MAX > S(p));
		check();
	}
	return 0;
}