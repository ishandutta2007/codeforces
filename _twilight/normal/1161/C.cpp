#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int main() {
	int n, mi = 142857, t = 1, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x < mi) {
			mi = x, t = 1;
		} else {
			t += (mi == x);
		}
	}
	puts((t <= (n >> 1)) ? ("Alice") : ("Bob"));
	return 0;
}