#include <bits/stdc++.h>

double A[111][2];

bool S[20010];
int main()
{
	int n;
	scanf("%d", &n);
	if(n <= 4) return puts("No solution"), 0;
	while(1) {
		int flag = 1;
		double rd = 100, x = 0.0, y = 0.0;
		memset(S, 0, sizeof S);
		for(int i = 1; i <= n; i++) {
			A[i][0] = x, A[i][1] = y;
			int tmp = (int) (1012 * (rand() / 16384.0 - 1.0));
			while(S[tmp + 10000]) tmp = (int) (1012 * (rand() / 16384.0 - 1.0));
			S[tmp + 10000] = 1;
			double nw = rd + tmp / 100.0, c = cos(2 * M_PI / n * i), s = sin(2 * M_PI / n * i);
			if(i == n - 1) {
				if(y < 0) {flag = 0; break;}
				nw = y / -s;
			}
			x += nw * c;
			y += nw * s;
			if(i == n - 1 && x > 0) {flag = 0; break;}
		}
		if(flag) {
			for(int i = 1; i <= n; i++) printf("%.12lf %.12lf\n", A[i][0], A[i][1]);
			return 0;
		}
	}
	return 0;
}