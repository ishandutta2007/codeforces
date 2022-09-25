#include<bits/stdc++.h>

using namespace std;

const int MX = 1000000;

int v[MX], c[MX], minC[20][MX + 1], maxV[20][MX + 1], pot[MX];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", v + i);
	for (int i = 0; i < n; i++) scanf("%d", c + i);
	
	for (int i = 0; i < n; i++) {
		minC[0][i] = c[i];
		maxV[0][i] = v[i];
	}
	
	for (int i = 0; i < 19; i++)
		for (int j = 0; j + (1 << i) < n; j++) {
			minC[i + 1][j] = min(minC[i][j], minC[i][j + (1 << i)]);
			maxV[i + 1][j] = max(maxV[i][j], maxV[i][j + (1 << i)]);
		}
	
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = (1 << 24); j > 0; j /= 2) {
			int mx = 0, p = i;
			for (int q = 19; q >= 0; q--)
				if (minC[q][p] >= res + j) {
					mx = max(maxV[q][p], mx);
					p += (1 << q);
				}
			
			if (100 * mx >= res + j) res += j;
		}
		
		pot[i] = res;
	}
	
	sort(pot, pot + n);
	
	long double ans = 0.0, coef = k / (long double)(n);
	for (int i = 0; i < n; i++) {
		ans += pot[i] * coef;
		
		if (i < n - 1) coef *= (n - k - i) / (long double)(n - i - 1);
	}
	
	printf("%.12lf\n", (double)ans);
	
	return 0;
}