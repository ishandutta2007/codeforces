#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int p1, p2, k;
		scanf("%d%d%d", &p1, &p2, &k);
		if (k == 1) {
			puts("REBEL");
			continue;
		}
		int g = gcd(p1, p2);
		p1 /= g;
		p2 /= g;
		if (p1 > p2) swap(p1, p2);
		if (p1 == p2) {
			puts("OBEY");
			continue;
		}
		int x = (p1 + p2 - 2) / p1;
		if (x < k) puts("OBEY");
		else puts("REBEL");
	}
	return 0;
}