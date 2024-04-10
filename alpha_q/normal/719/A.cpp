#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, s[N];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", s + i);

	if (s[n] == 0) {
		puts("UP");
		return 0;
	}

	if (s[n] == 15) {
		puts("DOWN");
		return 0;
	}

	if (n == 1) {
		puts("-1");
		return 0;
	}

	puts(s[n] > s[n - 1] ? "UP" : "DOWN");
	return 0;
}