#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

const int N = 3e5 + 5;

int n, hn;
int p[N];
vector<pii> op;

void S(int x, int y) {
	swap(p[x], p[y]);
	op.emplace_back(x, y);
}

void work(int x, int y) {
	if (x > y) {
		swap(x, y);
	}
	if (y - x >= hn) {
		S(x, y);
	} else if (x <= hn && y <= hn) {
		S(x, n);
		S(y, n);
		S(x, n);
	} else if (x > hn && y > hn) {
		S(x, 1);
		S(y, 1);
		S(x, 1);
	} else {
		assert(x <= hn && y > hn);
		S(x, n);
		S(y, 1);
		S(1, n);
		S(x, n);
		S(y, 1);
	}
}

int main() {
	scanf("%d", &n);
	hn = n >> 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; i++) {
		while (p[i] != i) {
			work(p[i], i);
		}
	}
	printf("%d\n", (signed) op.size());
	for (auto par : op) {
		printf("%d %d\n", par.first, par.second);
	}
	return 0;
}