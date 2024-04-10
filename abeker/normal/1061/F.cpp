#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int N, K;

int ask(int a, int b, int c) {
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	char ans[5];
	scanf("%s", ans);
	return ans[0] == 'Y';
}

inline int get(int n) {
	return uniform_int_distribution <int> (1, n)(rng);
}

void check(int x) {
	int y = (x - 1 + get(N - 1)) % N + 1;
	int subtree = 0;
	for (int i = 1; i <= N; i++) {
		subtree += !ask(i, x, y);
		if (subtree > (N - 1) / K)
			return;
	}
	
	if (subtree == (N - 1) / K) {
		printf("! %d\n", x);
		fflush(stdout);
		exit(0);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	
	set <int> all;
	for (int it = 0; it < 8; it++) {
		int u = get(N);
		int v = get(N);
		for (int i = 1; i <= N; i++)
			if (ask(u, i, v))
				all.insert(i);
	}
	
	for (auto it : all)
		check(it);
	
	return 0;
}