#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 501000
using namespace std;
char p[N_];
vector<int>E[N_];
int Deg[N_], n;
void Solve() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		E[i].clear();
		Deg[i] = 0;
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		Deg[a]++, Deg[b]++;
	}
	scanf("%s", p + 1);
	if (n <= 2) {
		puts("Draw");
		return;
	}
	int c3 = 0;
	for (i = 1; i <= n; i++) {
		if (Deg[i] >= 4) {
			puts("White");
			return;
		}
		if (Deg[i] >= 3) {
			c3++;
			int c = 0;
			for (auto &t : E[i])if (p[t] == 'W')c++;
			if (p[i] == 'W')c++;
			if (c) {
				puts("White");
				return;
			}
			c = 0;
			for (auto &t : E[i]) {
				if (Deg[t] != 1)c++;
			}
			if (c >= 2) {
				puts("White");
				return;
			}
		}
		if (Deg[i] >= 2) {
			if (n >= 4 && p[i] == 'W') {
				puts("White");
				return;
			}
		}
	}
	vector<int>V;
	for (i = 1; i <= n; i++)if (p[i] == 'W')V.push_back(i);
	if (n == 3) {
		if (V.size() >= 2) {
			puts("White");
		}
		else {
			puts("Draw");
		}
		return;
	}
	if (c3 >= 3) {
		puts("White");
		return;
	}
	if (c3 == 0) {
		if (V.size() <= 1) {
			puts("Draw");
			return;
		}
		if (n % 2 == 1) {
			puts("White");
		}
		else {
			puts("Draw");
		}
		return;
	}
	if (c3 == 1) {
		if (V.size() == 0) {
			puts("Draw");
			return;
		}
		if (n % 2 == 0) {
			puts("White");
		}
		else {
			puts("Draw");
		}
		return;
	}
	if (!V.empty()) {
		while (1) {}
	}
	if (n % 2 == 1) {
		puts("White");
	}
	else puts("Draw");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}