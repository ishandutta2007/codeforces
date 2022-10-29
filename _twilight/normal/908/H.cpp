#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pcopy(T* pst, const T* ped, T* pval) {
	for ( ; pst != ped; *(pst++) = *(pval++));
}

const int N = 50, S = 1 << 23;

int n;
int ans;
int a[N][N]; // 0 : or, 1 : xor, 2 : and, 3 : nothing
int G[24][24];	// after union
int uf[N], sz[N];
int f[S], g[S], bit[S];

int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}

boolean have_and = false;
inline void init() {
	static char str[N + 4];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		uf[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = 3;
			} else if (str[j] == 'A') {
				a[i][j] = 2;
				have_and = true;
				uf[find(i)] = find(j);
			} else if (str[j] == 'X') {
				a[i][j] = 1;
			}
		}
	}
}

void fwt(int* f, int n) {
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j++) {
			if (j & i) {
				f[j] += f[j ^ i];
			}
		}
	}
}

inline int discrete() {
	static int id[N];
	vector<int> val;
	for (int i = 0; i < n; i++) {
		sz[find(i)]++;
	}
	for (int i = 0; i < n; i++) {
		if (find(i) == i && sz[i] > 1) {
			val.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		id[i] = lower_bound(val.begin(), val.end(), find(i)) - val.begin();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int u = find(i), v = find(j);
			if (sz[u] == 1 || sz[v] == 1) {
				continue;
			}
			if (u ^ v) {
				G[id[u]][id[v]] |= a[i][j];
			}
		}
	}
	return val.size();
}

#define sgn(__) (((__) & 1) ? (-1) : (1))

inline void solve() {
	if (!have_and) {
		printf("%d\n", n - 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] == 1 && find(i) == find(j)) {
				puts("-1");
				return;
			}
		}
	}
	ans = n;
	n = discrete();
	f[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		int x = -1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				x = j;
				break;
			}
		}
		assert(~x);
		if (!f[i ^ (1 << x)])
			continue;
		f[i] = 1;
		for (int j = x + 1; j < n && f[i]; j++) {
			if (i & (1 << j)) {
				f[i] &= !G[x][j];	
			}
		}
	}
	pcopy(g, g + (1 << n), f);
	int all = (1 << n) - 1;
	bit[0] = 0;
	for (int s = 1; s <= all; s++) {
		bit[s] = bit[s >> 1] + (s & 1);
	}
	fwt(f, all + 1);
	fwt(g, all + 1);
	for (int cnt = 0; cnt <= n; cnt++, ans++) {
		int fn = 0;
		for (int j = 0; j <= all; j++) {
			fn += g[j] * sgn(n - bit[j]);
		}
		if (fn) {
			break;
		}
		for (int j = 0; j <= all; j++)
			g[j] = g[j] * f[j];
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}