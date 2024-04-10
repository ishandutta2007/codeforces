#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];

void check(int p) {
	for (int i = 0; i < N; i++)
		if (a[i] % p && b[i] % p)
			return;
	printf("%d\n", p);
	exit(0);
}

void go(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		check(i);
		while (!(x % i))
			x /= i;
	}
	if (x > 1)
		check(x);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
	
	go(a[0]);
	go(b[0]);
	
	puts("-1");
	
	return 0;
}