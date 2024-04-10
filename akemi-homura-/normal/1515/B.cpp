#include <bits/stdc++.h>
using namespace std;
inline bool isq(int x) {
	int s = round(sqrt(x));
	return s * s == x;
}
int n;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if ((n % 2 == 0 && isq(n / 2)) || (n % 4 == 0 && isq(n / 4))) {
			puts("YES");
		} else puts("NO");
	}
	return 0;
}