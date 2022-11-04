#include <bits/stdc++.h>
#define M 400010

using namespace std;

int n, A[M], B[M], WB[M];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &B[i]), WB[B[i]] = i;
	// special
	int is_special = 1;
	int w = B[n];
	for(int i = 1; i < w; i++)
		if(B[n - i] + 1 != B[n - i + 1]) is_special = 0;
	if(is_special == 1) {
		for(int i = w + 1; i <= n; i++)
			if(WB[i] > i - w - 1) is_special = 0;
	}
	if(is_special == 1) {
		printf("%d\n", n - w);
		return 0;
	}
	int mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, WB[i] - i + 1);
	printf("%d\n", n + mx);
	return 0;
}