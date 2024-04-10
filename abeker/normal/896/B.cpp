#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, M, C;
int a[MAXN];

int add_front(int x) {
	for (int i = 0; i < N; i++)
		if (!a[i] || a[i] > x) {
			a[i] = x;
			return i + 1;
		}
}

int add_back(int x) {
	for (int i = N - 1; i >= 0; i--)
		if (!a[i] || a[i] < x) {
			a[i] = x;
			return i + 1;
		}
}

bool sorted() {
	for (int i = 0; i < N; i++) {
		if (!a[i])
			return false;
		if (i && a[i - 1] > a[i])
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d%d", &N, &M, &C);
	do {
		int p;
		scanf("%d", &p);
		assert(p <= C);
		printf("%d\n", p <= C / 2 ? add_front(p) : add_back(p));
		fflush(stdout);
	} while (!sorted());
	return 0;
}