#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int C[110], n, CK[110], w[110];
vector<int>E[4];
int main() {
	int i, a, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		w[i] = a;
		C[a]++;
	}
	for (i = 1; i <= 100; i++) {
		if (C[i] == 1)E[1].push_back(i);
		if (C[i] == 2)E[2].push_back(i);
		if (C[i] >= 3)E[3].push_back(i);
	}
	if (E[1].size() % 2 == 1) {
		if (!E[3].size()) {
			puts("NO");
			return 0;
		}
		puts("YES");
		for (i = 0; i < E[1].size() / 2; i++)CK[E[1][i]] = 1;
		int x = E[3][0], ck = 0;
		for (j = 1; j <= n; j++) {
			if (CK[w[j]] || (w[j] == x && !ck)) {
				if (w[j] == x)ck = 1;
				printf("B");
			}
			else printf("A");
		}
		puts("");
		return 0;
	}
	puts("YES");
	for (i = 0; i < E[1].size() / 2; i++)CK[E[1][i]] = 1;
	for (j = 1; j <= n; j++) {
		if (CK[w[j]] ) {
			printf("B");
		}
		else printf("A");
	}
	puts("");
}