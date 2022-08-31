#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, Next[501000], ON, Res[501000];
struct Graph {
	int n, SZ, Q[1200000], Deg[1200000];
	vector<int>E[1200000];
	void Add_Edge(int a, int b) {
		E[a].push_back(b);
		Deg[b]++;
	}
	void init(int N) {
		int t = 1, i;
		while (t <= N)t *= 2;
		SZ = t;
		n = SZ*2;
		for (i = 1; i <= n; i++) {
			E[i].clear();
			Deg[i] = 0;
		}
		for (i = SZ * 2 - 1; i > 1; i--) {
			Add_Edge(i, i / 2);
		}
	}
	void AddRange(int b, int e, int a) {
		b += SZ, e += SZ;
		while (b <= e) {
			if (b & 1) Add_Edge(b, a + SZ);
			if (!(e & 1)) Add_Edge(e, a + SZ);
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
	}
	void Do() {
		int i, head = 0, tail = 0;
		for (i = 1; i <= n; i++) {
			if (!Deg[i])Q[++tail] = i;
		}
		while (head < tail) {
			int x = Q[++head];
			for (auto &y : E[x]) {
				Deg[y]--;
				if (!Deg[y])Q[++tail] = y;
			}
		}
		if (tail != n) {
			puts("-1");
			return;
		}
		int c = 0;
		for (i = 1; i <= n; i++) {
			if (Q[i] >= SZ + 1 && Q[i] <= SZ + ON) {
				Res[Q[i] - SZ] = ++c;
			}
		}
		for (i = 1; i <= ON; i++)printf("%d ", Res[i]);
		puts("");
	}
}T;
void Solve() {
	int i, n;
	scanf("%d", &n);
	ON = n;
	for (i = 1; i <= n; i++) {
		scanf("%d", &Next[i]);
	}
	T.init(n);
	for (i = 1; i <= n; i++) {
		if (Next[i] == -1) continue;
		T.AddRange(i + 1, Next[i] - 1, i);
		if (Next[i] != n + 1)T.Add_Edge(i + T.SZ, Next[i] + T.SZ);
	}
	T.Do();
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}