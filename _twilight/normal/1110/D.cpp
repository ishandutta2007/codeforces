#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;
const signed int inf = (signed) (~0u >> 1);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

int n, m;
int cnt[N];
int f[N][3][5];

void upd(int& a, int b) {
	if (a < b)
		a = b;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		cnt[x + 2]++;
	}
	pfill(f[0][0], f[m + 3][0], -inf);
	f[2][0][0] = 0;
	for (int i = 3; i <= m + 2; i++) {
		for (int a = 0; a <= 2 && a <= cnt[i - 2]; a++) {
			for (int b = 0, v; b <= 4 && b <= cnt[i - 1]; b++) {
				v = f[i - 1][a][b];
				if (v == -inf)
					continue;
				for (int c = min(a, b), s = min(a, b); c <= 6 && c <= cnt[i]; c++) {
					upd(f[i][min(b - s, 2)][min(c - s, 4)], (cnt[i] - c) / 3 + s + v);
				}	
			}
		}
	}
	int ans = -inf;
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 4; b++) {
			ans = max(ans, f[m + 2][a][b]);
		}
	}
	printf("%d\n", ans);
	return 0;
}