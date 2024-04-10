#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int mx = 0;
	while (N--) {
		int b;
		scanf("%d", &b);
		int a = b + mx;
		printf("%d ", a);
		mx = max(mx, a);
	}
	puts("");
	return 0;
}