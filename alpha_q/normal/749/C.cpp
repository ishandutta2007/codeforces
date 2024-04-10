#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
char s[N];
bool off[N];

int main (int argc, char const *argv[]) {
	scanf("%d %s", &n, s);
	int dcut = 0, rcut = 0, d = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'D') ++d;
		else ++r;
	}
	for (int i = 0; d and r; i = (i + 1) % n) {
		if (off[i]) continue;
		if (s[i] == 'D') {
			if (dcut) off[i] = 1, --dcut;
			else ++rcut, --r;
		} else {
			if (rcut) off[i] = 1, --rcut;
			else ++dcut, --d;
		}
	}
	if (d == 0) puts("R");
	else puts("D");
    return 0;
}