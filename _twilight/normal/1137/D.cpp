#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int read() {
	int k, x;
	fflush(stdin);
	scanf("%d", &k);
	for (x = k; x; scanf("%*s"), x--);
	return k;
}

int main() {
	do {
		puts("next 0");
		fflush(stdout);
		read();
		puts("next 0 1");
		fflush(stdout);
	} while (read() != 2);
	do {
		puts("next 0 1 2 3 4 5 6 7 8 9");
		fflush(stdout);
	} while (read() != 1);
	puts("done");
	fflush(stdout);
	return 0;
}