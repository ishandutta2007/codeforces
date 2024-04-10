#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2005;

int n;
bitset<N> G[N];
int deg[N], bkt[N];

void read(int p) {
	static char s[N];
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			G[p].set(i);
			deg[p]++;
		}
	}
}

boolean check() {
	memset(bkt, 0, sizeof(int) * n);
	for (int i = 1; i <= n; i++)
		bkt[deg[i]]++;
	int sumd = 0, sumc = 0;
	for (int i = n - 1; ~i; i--) {
		sumd += i * bkt[i], sumc += bkt[i];
		if ((sumd == sumc * (sumc - 1) / 2 + sumc * (n - sumc)) && sumc < n && sumc) {
			return false;
		}
	}
	return true;
}

void flip(int v) {
	for (int i = 1; i <= n; i++) {
		if (i == v)
			continue;
		if (G[v].test(i)) {
			--deg[v], ++deg[i];
		} else {
			++deg[v], --deg[i];
		}
		G[v].flip(i);
		G[i].flip(v);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		read(i);
	if (check()) {
		puts("0 1");
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		flip(i);
		cnt += check();
		flip(i);
	}
	if (cnt) {
		printf("1 %d\n", cnt);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			flip(i), flip(j);
			cnt += check();
			flip(i), flip(j);
		}
	}
	if (cnt) {
		printf("2 %d\n", cnt * 2);
		return 0;
	}
	puts("-1");
	return 0;
}