#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[2010];
int w[2010], root, n, Num[2010], ord[2010], cnt, vis[2010], Res[2010], Rank[2010], Ed[2010], inp[2010];
void DFS(int a, int pp) {
	Num[a] = ++cnt;
	ord[cnt] = a;
	for (auto &x : E[a]) {
		DFS(x, a);
	}
	Ed[a] = cnt;
}
int main() {
	int i, a, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (a) {
			E[a].push_back(i);
		}
		else {
			root = i;
		}
		scanf("%d", &w[i]);
		inp[i] = w[i];
	}
	DFS(root, 0);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (!vis[ord[j]] && !w[ord[j]])break;
		}
		if (j == n + 1) {
			puts("NO");
			return 0;
		}
		int x = ord[j];
		vis[x] = 1;
		Res[i] = x;
		Rank[x] = i;
		for (j = 1; j <= n; j++) {
			if (Num[j] < Num[x] && Num[x] <= Ed[j] && !vis[j]) {
				w[j]--;
				if (w[j] < 0) {
					puts("NO");
					return 0;
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		int c = 0;
		for (j = 1; j <= n; j++) {
			if (Num[i] < Num[j] && Num[j] <= Ed[i]) {
				if (Rank[i] > Rank[j])c++;
			}
		}
		if (c != inp[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (i = 1; i <= n; i++)printf("%d ", Rank[i]);
}