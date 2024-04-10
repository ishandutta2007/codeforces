#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
int fi = -1, id, sc = -1;

int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (fi != -1 && id != x) {
			ans = max(ans, i - fi);		
		}
		if (sc != -1) {
			ans = max(ans, i - sc);
		}
		if (fi == -1) {
			fi = i;
			id = x;
		} else if (x != id && sc == -1) {
			sc = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}