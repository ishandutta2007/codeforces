#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
int a, b;
char s[212345];

int main() {
	scanf("%d%s", &n, s + 1);
	a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			if (a <= b) {
				putchar('0');
				a++;
			} else {
				putchar('1');
				b++;
			}
		} else {
			if (a >= b) {
				putchar('0');
				a--;
			} else {
				putchar('1');
				b--;
			}
		}
	}
	return 0;
}