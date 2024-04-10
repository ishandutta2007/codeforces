#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pcopy(T* pst, const T* ped, T* val) {
	for ( ; pst != ped; *(pst++) = *(val++));
}

template <typename T>
class Matrix {
	public:
		int r, c;
		T* a;

		Matrix() : a(NULL) {	}
		Matrix(int r, int c) : r(r), c(c) {
			a = new T[(r * c)];
		}

		T* operator [] (int p) {
			return a + c * p;
		}
};

int n, m;
Matrix<char> a, b;

inline void init() {
	scanf("%d%d", &n, &m);
	a = Matrix<char>(n + 1, m + 5);
	b = Matrix<char>(n + 1, m + 5);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
}

boolean *rev;
boolean *tmp_row, *tmp_col;
inline void solve() {
	char str[6] = "ACGT", per[6];
	int ans = 14285714;
	int flag = 0;	// 0 : row, 1 : col
	rev = new boolean[(max(n, m) + 1)];
	tmp_row = new boolean[(n + 1)];
	tmp_col = new boolean[(m + 1)];
	do {
		b[0][0] = str[0], b[0][1] = str[1];
		b[1][0] = str[2], b[1][1] = str[3];
//		cerr << str << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i >= 2 || j >= 2) {
					b[i][j] = b[i & 1][j & 1];
				}
			}
		}
		int cmp_row = 0, cmp_col = 0;
		// adjust row
		for (int i = 0; i < n; i++) {
			int cost1 = 0, cost2 = 0;
			char x = b[i][0], y = b[i][1];
			for (int j = 0; j < m; j++) {
				cost1 += (b[i][j] != a[i][j]);
			}
			for (int j = 0; j < m; j++) {
				cost2 += ((b[i][j] ^ x ^ y) != a[i][j]);
			}
			tmp_row[i] = (cost1 > cost2);
			cmp_row += min(cost1, cost2);
		}
		if (cmp_row < ans) {
			ans = cmp_row;
			flag = 0;
			pcopy(per, per + 4, str);
			pcopy(rev, rev + n, tmp_row);
		}
		
		// adjust col
		for (int i = 0; i < m; i++) {
			int cost1 = 0, cost2 = 0;
			char x = b[0][i], y = b[1][i];
			for (int j = 0; j < n; j++) {
				cost1 += (b[j][i] != a[j][i]);
			}
			for (int j = 0; j < n; j++) {
				cost2 += ((b[j][i] ^ x ^ y) != a[j][i]);
			}
			tmp_col[i] = (cost1 > cost2);
			cmp_col += min(cost1, cost2);
		}
		if (cmp_col < ans) {
			ans = cmp_col;
			flag = 1;
			pcopy(per, per + 4, str);
			pcopy(rev, rev + m, tmp_col);
		}
	} while (next_permutation(str, str + 4));
	
	b[0][0] = per[0], b[0][1] = per[1];
	b[1][0] = per[2], b[1][1] = per[3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i >= 2 || j >= 2) {
				b[i][j] = b[i & 1][j & 1];
			}
		}
	}
//	cerr << ans << '\n';
	if (!flag) {
		for (int i = 0; i < n; i++) {
			char x = b[i][0], y = b[i][1];
			for (int j = 0; j < m; j++) {
				putchar(b[i][j] ^ (rev[i] * (x ^ y)));
			}
			putchar('\n');
		}
	} else {
		for (int i = 0; i < m; i++) {
			if (!rev[i])
				continue;
			char x = b[0][i], y = b[1][i];
			for (int j = 0; j < n; j++) {
				b[j][i] ^= x ^ y;
			}
		}
		for (int i = 0; i < n; i++, putchar('\n')) {
			for (int j = 0; j < m; j++) {
				putchar(b[i][j]);
			}
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}