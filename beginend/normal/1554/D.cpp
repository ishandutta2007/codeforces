#include<bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n & 1) {
			for (int i = 1; i <= n / 2; i++) putchar('a');
			putchar('b');
			if (n > 1) putchar('c');
			for (int i = 1; i < n / 2; i++) putchar('a');
		}
		else {
			for (int i = 1; i <= n / 2; i++) putchar('a');
			putchar('b');
			for (int i = 1; i < n / 2; i++) putchar('a');
		}
		puts("");
	}
	return 0;
}