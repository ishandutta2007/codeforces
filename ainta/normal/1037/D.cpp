#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
vector<int>E[N_], T[N_];
int n, w[N_], Dep[N_], Num[N_], Q[N_], head, tail;
void DFS(int a, int pp) {
	for (auto &x : E[a]) {
		if (x != pp) {
			T[a].push_back(x);
			DFS(x, a);
		}
	}
}
struct point {
	int ord, a;
	bool operator<(const point &p)const {
		return ord < p.ord;
	}
}O[N_];
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Num[w[i]] = i;
	}
	if (w[1] != 1) {
		puts("No");
		return 0;
	}
	Q[++tail] = 1;
	while (head < tail) {
		int x = Q[++head];
		int c = 0;
		for (auto &y : T[x]) {
			O[c++] = { Num[y],y };
		}
		sort(O, O + c);
		for (i = 0; i < c; i++) {
			Q[++tail] = O[i].a;
		}
	}
	for (i = 1; i <= n; i++) {
		if (Q[i] != w[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}