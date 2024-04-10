#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN], b[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

bool solve() {
	bool plus = false, minus = false;
	for (int i = 0; i < N; i++) {
		if (b[i] < a[i] && !minus)
			return false;
		if (b[i] > a[i] && !plus)
			return false;
		if (a[i] == 1)
			plus = true;
		if (a[i] == -1)
			minus = true;
	}
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}