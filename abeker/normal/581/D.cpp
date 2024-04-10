#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int x[5], y[5];

void rot(int mask) {
	for (int i = 0; i < 3; i++)
		if (mask >> i & 1) 
			swap(x[i], y[i]);
}

void output(int a, int b, char c) {
	for (int i = 0; i < a; i++, puts(""))
		for (int j = 0; j < b; j++)
			putchar(c);
}

void solve() {
	int sumx = 0, sumy = 0;
	for (int i = 0; i < 3; i++) {
		sumx += x[i];
		sumy += y[i];
	}
	
	bool ok = true;
	for (int i = 0; i < 3; i++)
		ok &= x[i] == x[0];
	
	if (ok && sumy == x[0]) {
		printf("%d\n", x[0]);
		for (int i = 0; i < x[0]; i++, puts(""))	
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < y[j]; k++)
					putchar('A' + j);
		exit(0);
	}
	
	ok = true;
	for (int i = 0; i < 3; i++)
		ok &= y[i] == y[0];
	
	if (ok && sumx == y[0]) {
		printf("%d\n", y[0]);
		for (int i = 0; i < 3; i++)
			output(x[i], y[i], 'A' + i);
		exit(0);
	}
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if (i == j || j == k || k == i) continue;
				if (x[i] == x[j] && y[i] + y[j] == y[k] && x[i] + x[k] == y[k]) {
					printf("%d\n", y[k]);
					for (int l = 0; l < x[i]; l++, puts("")) {
						for (int m = 0; m < y[i]; m++)
							putchar('A' + i);
						for (int m = 0; m < y[j]; m++)
							putchar('A' + j);
					}
					output(x[k], y[k], 'A' + k);
					exit(0);
				}
			}
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if (i == j || j == k || k == i) continue;
				if (y[i] == y[j] && x[i] + x[j] == x[k] && y[i] + y[k] == x[k]) {
					printf("%d\n", x[k]);
					for (int l = 0; l < x[i]; l++, puts("")) {
						for (int m = 0; m < y[i]; m++)
							putchar('A' + i);
						for (int m = 0; m < y[k]; m++)
							putchar('A' + k);
					}
					for (int l = 0; l < x[j]; l++, puts("")) {
						for (int m = 0; m < y[j]; m++)
							putchar('A' + j);
						for (int m = 0; m < y[k]; m++)
							putchar('A' + k);
					}
					exit(0);
				}
			}
}

int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d%d", x + i, y + i);
	
	for (int i = 0; i < 8; i++) {
		rot(i);
		solve();
		rot(i);
	}
	puts("-1");
	return 0;	
}