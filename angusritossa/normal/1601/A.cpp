#include <bits/stdc++.h>
using namespace std;
int numWithBit[30];
int t;
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		fill_n(numWithBit, 30, 0);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			for (int b = 0; b < 30; b++) {
				if (a & (1 << b)) numWithBit[b]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			bool good = 1;
			for (int j = 0; j < 30; j++) {
				if (numWithBit[j]%i) good = false;
			}
			if (good) printf("%d ", i);
		}
		printf("\n");
	}
}