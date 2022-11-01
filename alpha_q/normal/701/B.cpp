#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool ro[N], col[N];
int n, m, x, y;
long long tot;

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	scanf("%d %d", &n, &m);
	tot = (long long) n * (long long) n;
	int p = n, q = n;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &x, &y);
		
		if (ro[x] and col[y]) {
			printf("%lld ", tot);
		} else if (ro[x]) {
			col[y] = 1;
			q--;
			tot -= p;
			printf("%lld ", tot);
		} else if (col[y]) {
			ro[x] = 1;
			p--;
			tot -= q;
			printf("%lld ", tot);
		} else {
			ro[x] = col[y] = 1;
			tot -= (p + q - 1);
			p--, q--;
			printf("%lld ", tot);
		}
	}
	return 0;
}