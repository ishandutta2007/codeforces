#include<cstdio>
#include<algorithm>
using namespace std;
int n, vis[110][110];
int main() {
	int i, c, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &c);
		while (c--) {
			scanf("%d", &a);
			vis[a][i] = 1;
		}
	}
	for (i = 1; i <= 100; i++) {
		int ck = 0;
		for (int j = 1; j <= n; j++)if (!vis[i][j])ck = 1;
		if (!ck)printf("%d ", i);
	}
}