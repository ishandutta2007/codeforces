#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, Deg[1010], par[1010], w[1010];
vector<int>E[1010], L[1010];
void DFS(int a, int pp) {
	int i;
	for (i = 0; i < E[a].size(); i++) {
		int x = E[a][i];
		if (x == pp)continue;
		par[x] = a;
		w[x] = L[a][i];
		DFS(x, a);
	}
}
struct AA {
	int a, b, c;
};
vector<AA>Res;
void Add(int a, int b, int c) {
	Res.push_back({ a,b,c });
}
vector<int>TP, TP2;
bool Go(int a, int pp) {
	
	int ck = 0;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		ck = 1;
		if (Go(x, a))return true;
	}
	if (!ck) {
		TP.push_back(a);
		return true;
	}
	return false;
}
int main() {
	int i, a, b, c;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(c);
		L[b].push_back(c);
	}
	if (n == 2) {
		puts("YES");
		printf("1\n");
		printf("%d %d %d\n", 1, 2, c);
		return 0;
	}
	for (i = 1; i <= n; i++) {
		if (E[i].size() == 2) {
			puts("NO");
			return 0;
		}
	}
	DFS(1, 0);
	for (i = 2; i <= n; i++) {
		int a = i;
		int b = par[i];
		int c = w[i];
		if (E[a].size() == 1) {
			TP.clear();
			int rem = 2;
			for (auto &t : E[b]) {
				if (t != a && rem) {
					Go(t, b);
					rem--;
				}
			}
			Add(TP[0], TP[1], -c/2);
			Add(TP[0], a, c/2);
			Add(TP[1], a, c/2);
		}
		else if (E[b].size() == 1) {
			TP.clear();
			int rem = 2;
			for (auto &t : E[a]) {
				if (t != b && rem) {
					Go(t, a);
					rem--;
				}
			}
			Add(TP[0], TP[1], -c/2);
			Add(TP[0], b, c / 2);
			Add(TP[1], b, c / 2);
		}
		else {
			TP.clear();

			int rem = 2;
			for (auto &t : E[a]) {
				if (t != b && rem) {
					Go(t, a);
					rem--;
				}
			}

			TP2 = TP;
			TP.clear();



			rem = 2;
			for (auto &t : E[b]) {
				if (t != a && rem) {
					Go(t, b);
					rem--;
				}
			}

			Add(TP[0], TP[1], -c/2);
			Add(TP2[0], TP2[1], -c/2);
			Add(TP[0], TP2[1], c/2);
			Add(TP2[0], TP[1], c/2);
	
		}
	}
	puts("YES");
	printf("%d\n", Res.size());
	for (auto &x : Res) {
		printf("%d %d %d\n", x.a, x.b, x.c);
	}
}