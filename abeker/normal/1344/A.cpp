#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int N;
	scanf("%d", &N);
	vector <bool> bio(N);
	bool res = true;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		x += i;
		x %= N;
		if (x < 0)
			x += N;
		res &= !bio[x];
		bio[x] = true;
	}
	return res;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
		puts(solve() ? "YES" : "NO");
	return 0;
}