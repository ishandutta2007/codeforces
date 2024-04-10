#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
bitset <N> m;
vector <int> pr, res;

void sieve (void) {
	for (int i = 2; i < N; ++i) if (!m[i])
		for (int j = i * i; j < N; j += i) m[j] = 1;
	for (int i = 2; i < N; ++i) if (!m[i]) pr.push_back(i);
}

int main (int argc, char const *argv[]) {
	sieve(); scanf("%d", &n);
	for (int i = 0; pr[i] <= n; ++i) {
		int p = pr[i];
		while (p <= n) res.push_back(p), p *= pr[i];
	}
	printf("%d\n", (int) res.size());
	for (int x : res) printf("%d ", x);
	puts("");
	return 0;
}