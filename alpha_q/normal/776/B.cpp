#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

int n;
bitset <N> vis;

void sieve (void) {
	for (int i = 2; i * i < N; ++i) if (!vis[i]) {
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

int main (int argc, char const *argv[]) {
	sieve(); cin >> n;
	if (n == 1) {
		puts("1\n1");
		return 0;
	} else if (n == 2) {
		puts("1\n1 1");
		return 0;
	}
	puts("2");
	for (int i = 2; i <= n + 1; ++i) {
		if (vis[i]) printf("2 ");
		else printf("1 ");
	}
	puts("");
    return 0;
}