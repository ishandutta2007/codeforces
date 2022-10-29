#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, m;
int limit[N];
int c[6], clim[64];
char str[N], tmp[10];

inline void init() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++) {
		c[str[i] -= 'a']++;
	}
	for (int i = 1; i <= n; i++) {
		limit[i] = 63;
	}
	scanf("%d", &m);
	for (int i = 1, pos, len, mrk; i <= m; i++) {
		scanf("%d%s", &pos, tmp);
		len = strlen(tmp), mrk = 0;
		for (int j = 0; j < len; j++) {
			mrk |= (1 << (tmp[j] - 'a'));
		}
		limit[pos] = mrk;
	}
	for (int i = 1; i <= n; i++) {
		clim[limit[i]]++;
	}
}

int f[64];
boolean calc() {
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			if (i & j) {
				f[i] += clim[j];
			}
		}
	}
//	for (int i = 0; i < 64; i++) {
//		cerr << f[i] << " ";
//	}
//	cerr << '\n';
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 6; j++) {
			if ((i >> j) & 1) {
				f[i] -= c[j];
			}
		}
		if (f[i] < 0) {
			return false;
		}
	}
	return true;
}

char ans[N];
inline void solve() {
	if (!calc()) {
		puts("Impossible");
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 64; j++) {
			if (j & limit[i]) {
				f[j]--;	
			}
		}
		for (int c = 0; c < 6; c++) {
			if (((limit[i] >> c) & 1) && :: c[c] > 0) {
				boolean aflag = false;
				for (int j = 0; j < 64; j++) {
					if ((j >> c) & 1) {
						f[j]++;
					}
				}
				for (int j = 0; j < 64 && !aflag; j++) {
					if (f[j] < 0) {
						aflag = true;
					}
				}
				if (!aflag) {
					ans[i] = c + 'a';
					:: c[c]--;
					break;
				} else {
					for (int j = 0; j < 64; j++) {
						if ((j >> c) & 1) {
							f[j]--;
						}
					}	
				}
			}
		}
	}
	puts(ans + 1);
}

int main() {
	init();
	solve();
	return 0;
}