#include "bits/stdc++.h"
using namespace std;

int main() {
	int A; int B; int C; int N;
	while (~scanf("%d%d%d%d", &A, &B, &C, &N)) {
		int D = N - A - B + C;
		int a = A - C, b = B - C;
		if (A > N || B > N || C > N || D > N || D < 0 || a < 0 || b < 0 || D == 0) {
			puts("-1");
		} else {
			printf("%d\n", D);
		}
	}
}