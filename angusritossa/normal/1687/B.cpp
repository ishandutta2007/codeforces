#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 510
int cap[MAXN];
int tot;
int include[MAXN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		printf("? ");
		for (int j = 0; j < m; j++) {
			printf("%c", i == j ? '1' : '0');
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &cap[i]);
	}
	vector<pair<int, int> > sorted;
	for (int i = 0; i < m; i++) {
		sorted.push_back({cap[i], i});
	}
	sort(sorted.begin(), sorted.end());
	for (auto a : sorted) {
		tot += a.first;
		include[a.second] = 1;
		printf("? ");
		for (int i = 0; i < m; i++) {
			printf("%d", include[i]);
		}
		printf("\n");
		fflush(stdout);
		int res;
		scanf("%d", &res);
		if (res != tot) {
			include[a.second] = 0;
			tot -= a.first;
		}
	}
	printf("! %d\n", tot);
	fflush(stdout);
}