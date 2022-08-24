#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[1010];
vector<int>E[1010];
int main() {
	int i, a, j;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	for (i = 1; i <= n; i++) {
		if (E[i].empty())continue;
		int c = 0;
		for (j = 0; j < E[i].size(); j++) {
			if (E[E[i][j]].empty())c++;
		}
		if (c < 3) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}