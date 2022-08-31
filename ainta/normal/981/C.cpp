#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
vector<int>E[N_], Ch[N_];
int n;
void DFS(int a, int pp) {
	for (auto &x : E[a]) {
		if (x != pp) {
			Ch[a].push_back(x);
			DFS(x, a);
		}
	}
}
int main() {
	int a, b, i;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	vector<int>T;
	for (i = 1; i <= n; i++) {
		if (E[i].size() >= 3)T.push_back(i);
	}
	if (T.size() >= 2) {
		puts("No");
		return 0;
	}
	if (T.size() == 0) {
		T.push_back(1);
	}
	DFS(T[0], 0);
	vector<int>Res;
	for (i = 1; i <= n; i++) {
		if (Ch[i].empty()) {
			Res.push_back(i);
		}
	}
	puts("Yes");
	printf("%d\n", Res.size());
	for (auto &t : Res) {
		printf("%d %d\n", T[0], t);
	}
}