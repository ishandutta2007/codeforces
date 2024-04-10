#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e3 + 5;

typedef class Pair4 {
	public:
		int x1, y1, x2, y2;

		Pair4(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {	}

		void print() {
			printf("%d %d %d %d\n", x1, y1, x2, y2);
		}
} Pair4;

int n;
int r[N], c[N];
int a[N], b[N];
int p[N], q[N];
int _r[N], _c[N];
vector<Pair4> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		r[i] = c[i] = i;
		_r[i] = _c[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		q[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (r[i] != p[i] || c[i] != q[i]) {
			// person p[i] -> i
			int x = _r[p[i]], y = _c[q[i]];
			ans.emplace_back(x, i, i, y);
			swap(r[i], r[x]);
			swap(_r[r[i]], _r[r[x]]);
			swap(c[i], c[y]);
			swap(_c[c[i]], _c[c[y]]);
		}
	}
	printf("%d\n", ans.size());
	for (auto p : ans) {
		p.print();
	}
	return 0;
}