#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int inv[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
}

bool solve() {
	for (int i = 2; i <= N; i++)
		if (inv[i] > inv[i - 1] + 1)
			return false;
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		puts(solve() ? "Yes" : "No");
	}
	return 0;
}