#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct BIT {
	int n, bit[270000];
	inline void Init(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++) bit[i] = 0;
	}
	inline void add(int i) {
		i++;
		while (i <= n) {
			bit[i] ^= 1;
			i += i & -i;
		}
	}
	inline int sum(int i) {
		i++;
		int ret = 0;
		while (i > 0) {
			ret ^= bit[i];
			i -= i & -i;
		}
		return ret;
	}
	inline int sum(int l, int r) {
		return sum(r) ^ sum(l - 1);
	}
} bit;
int n, m, q, cnt[N], L[N], R[N], ans[N][18];
vector<pair<pair<int, int>, int> > buck[18][N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int col;
		scanf("%d", &col);
		cnt[col] ^= 1;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		for (int j = 0; j < 18; j++) {
			int l = (L[i] + (1 << j)) % (1 << (j + 1)), r = (L[i] + (1 << (j + 1)) - 1) % (1 << (j + 1));
			if (l <= r) {
				buck[j][L[i]].push_back(make_pair(make_pair(l, r), i));
				buck[j][R[i] + 1].push_back(make_pair(make_pair(l, r), i));
			} else {
				buck[j][L[i]].push_back(make_pair(make_pair(l, (1 << (j + 1)) - 1), i));
				buck[j][L[i]].push_back(make_pair(make_pair(0, r), i));
				buck[j][R[i] + 1].push_back(make_pair(make_pair(l, (1 << (j + 1)) - 1), i));
				buck[j][R[i] + 1].push_back(make_pair(make_pair(0, r), i));
			}
		}
	}
	for (int j = 0; j < 18; j++) {
		bit.Init(1 << (j + 1));
		for (int i = m; i >= 1; i--) {
			if (cnt[i]) {
				bit.add(i % (1 << (j + 1)));
			}
			for (auto &P : buck[j][i]) {
				ans[P.second][j] ^= bit.sum(P.first.first, P.first.second);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int ok = 0;
		for (int j = 0; j < 18; j++) if (ans[i][j]) { ok = 1; break; }
		if (ok) putchar('A');
		else putchar('B');
	}
	return 0;
}