#include <bits/stdc++.h>

using namespace std;

char s[42][42];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	if (n == 1) {
		printf("1\no\n");
		return 0;
	}
	
	if (n == 2) {
		printf("%d\n", -1);
		return 0;
	}
	
	int d = n % 2;
	while ((d + 2) * (d + 2) <= n) d += 2;
	
	memset(s, '.', sizeof s);
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			s[i][j] = 'o';
	
	n -= d * d;
	
	int m = d;
	for (int i = 0; n > 0; i++, m++) {
		for (int j = 0; j < d && n > 0; j++, n -= 2) {
			s[d + i][j] = s[j][d + i] = 'o';
		}
	}
	
	printf("%d\n", m);
	for (int i = m - 1; i >= 0; i--) {
		s[i][m] = 0;
		printf("%s\n", s[i]);
	}
	
	return 0;
}