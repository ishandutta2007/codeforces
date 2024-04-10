#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

bitset <N> vis;
int n, tot[N], sp[N];

void sieve (void) {
	for (int i = 2; i * i < N; ++i) if (!vis[i]) {
		sp[i] = i;
		for (int j = i * i; j < N; j += i) if (!vis[j]) {
			sp[j] = i, vis[j] = 1;
		}
	}
	for (int i = 2; i < N; ++i) {
		if (sp[i] == 0) sp[i] = i;
	}
}

int main (int argc, char const *argv[]) {
	sieve();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		while (x > 1) {
			int p = sp[x];
			++tot[p];
			while (x % p == 0) x /= p;
		}
	}
	int res = 1;
	for (int i = 0; i < N; ++i) {
		res = max(res, tot[i]);
	}
	printf("%d\n", res);
	return 0;
}