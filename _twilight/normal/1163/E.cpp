#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int bzmax = 25;

typedef class LinearBasis {
	public:
		int a[30], b[30];

		LinearBasis() {
			clear();
		}

		void insert(int x) {
			int y = 0;
			for (int i = bzmax - 1; ~i; i--) {
				if ((x >> i) & 1) {
					x ^= a[i];
					y ^= b[i];
				}
				if ((x >> i) & 1) {
					a[i] = x;
					b[i] = y | (1 << i);
					break;
				}
			}
		}
		int get_mask(int x) {
			int y = 0;
			for (int i = bzmax - 1; ~i && x; i--) {
				if ((x >> i) & 1) {
					x ^= a[i];
					y ^= b[i];
				}
			}
			return (!x) ? (y) : (-1);
		}
		void clear() {
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
		}
} LinearBasis;

int n;
int a[200005];
int P[1 << 20];
LinearBasis lb;

boolean work(int m) {
	lb.clear();
	int N = 1 << m;
	for (int i = 1; i <= n; i++) {
		if (a[i] < N) {
			lb.insert(a[i]);
		}
	}
	for (int i = 0, x; i < N; i++) {
		if ((x = lb.get_mask(i)) == -1) {
			return false;
		}
		P[x] = i;
	}
	vector<int> Gray {0};
	for (int i = 1; i <= m; i++) {
		int msk = 1 << (i - 1);
		for (int j = msk - 1; ~j; j--) {
			Gray.push_back(Gray[j] | msk);
		}
	}
	printf("%d\n", m);
	for (int i = 0; i < N; i++) {
		printf("%d ", P[Gray[i]]);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 19; ~i; i--) {
		if (work(i)) {
			return 0;
		}
	}
	return 0;
}