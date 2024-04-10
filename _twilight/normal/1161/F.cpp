#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 55;

int T, n;
int a[N][N];
int match[N];
vector<int> G[N], I[N];

void marry() {
	vector<int> fL, sR;
	for (int i = 1; i <= n; i++) {
		fL.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		match[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		G[i].clear();
		for (int j = 1; j <= n; j++) {
			G[i].push_back(j);
		}
		sort(G[i].begin(), G[i].end(), [&] (int x, int y) {	return a[i][x] > a[i][y];	});
	}
	while (!fL.empty()) {
		for (auto p : fL) {
			I[G[p].back()].push_back(p);
			sR.push_back(G[p].back());
			G[p].pop_back();
		}
		fL.clear();
		for (auto p : sR) {
			int id = match[p];
			for (auto e : I[p]) {
				if (a[e][p] > a[id][p] || !id) {
					id = e;
				}
			}
			for (auto x : I[p]) {
				if (x ^ id) {
					fL.push_back(x);
				}	
			}
			if ((id ^ match[p]) && match[p]) {
				fL.push_back(match[p]);
			}
			match[p] = id;
			I[p].clear();
		}
	}
}

int _match[N];
int main() {
	static char mode[5];
	int p;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", a[i] + j);
			}
		}
		puts("B");
		fflush(stdout);
		scanf("%s%d", mode, &p);
		if ((mode[0] == 'D') ^ (p > n)) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					a[i][j] = n * n - a[i][j] + 1;
				}
			}
		}
		marry();
		if (p <= n) {
			for (int i = 1; i <= n; i++) {
				_match[match[i]] = i;
			}
			do {
				printf("%d\n", _match[p] + n);
				fflush(stdout);
			} while (~scanf("%d", &p) && p > 0);
		} else {
			do {
				printf("%d\n", match[p - n]);
				fflush(stdout);
			} while (~scanf("%d", &p) && p > 0);
		}
	}
	return 0;
}