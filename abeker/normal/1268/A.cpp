#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, K;
char a[MAXN], b[MAXN];

int main() {
	scanf("%d%d%s", &N, &K, a);

	for (int i = 0; i < N; i++)
		b[i] = a[i % K];
	
	bool ok = true;
	for (int i = 0; i < N; i++)
		if (b[i] != a[i]) {
			ok = b[i] > a[i];
			break;
		}
	
	if (ok) {
		printf("%d\n%s\n", N, b);
		return 0;
	}
	
	for (int i = K - 1; i >= 0; i--) {
		if (b[i] != '9') {
			b[i]++;
			break;
		}
		b[i] = '0';
	}
	
	for (int i = K; i < N; i++)
		b[i] = b[i - K];
	
	printf("%d\n%s\n", N, b);
	
	return 0;
}