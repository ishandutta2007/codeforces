#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e3 + 5;

#define ll long long

int n;
int b[5][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", b[i] + j);
	ll v = 1ll * b[1][2] * b[1][3] / b[2][3];
	int a = sqrt(v + 0.1);
	printf("%d ", a);
	for (int i = 2; i <= n; i++) {
		printf("%d ", b[1][i] / a);
	}
	return 0;
}