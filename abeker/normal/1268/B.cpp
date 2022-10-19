#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	long long black = 0, white = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		int w = (x + 1) / 2;
		int b = x / 2;
		if (i % 2)
			swap(w, b);
		black += b;
		white += w;
	}
	printf("%lld\n", min(black, white));
	return 0;
}