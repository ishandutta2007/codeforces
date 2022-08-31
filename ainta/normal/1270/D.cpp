#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int n, K, w[600], Z[600], vis[600];
int main() {
	scanf("%d%d", &n, &K);
	if (K == 1) {
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	set<int>Set;
	int i, a, b;
	for (i = 1; i <=K - 1; i++) {
		Set.insert(i);
	}
	for (i = K; i <= n; i++) {
		Set.insert(i);
		printf("? ");
		for (auto &t : Set)printf("%d ", t);
		puts("");
		fflush(stdout);
		scanf("%d%d", &a, &b);
		w[a] = b;
		Z[i] = a;
		vis[a] = 1;
		Set.erase(a);
	}
	if (K * 2 <= n + 1) {
		vector<int>T;
		for (i = 1; i <= n; i++) {
			if (vis[i] && T.size()<K)T.push_back(i);
		}
		printf("? ");
		for (auto &t : T)printf("%d ", t);
		puts("");
		fflush(stdout);
		scanf("%d%d", &a, &b);
		int c = 0;
		for (auto &t : T) {
			if (w[t] <= b)c++;
		}
		printf("! %d\n", c);
		fflush(stdout);
		return 0;
	}
	vector<int>V;
	for (auto &t : Set) {
		V.push_back(t);
	}
	Set.insert(Z[n]);
	int AA = w[Z[n]];
	int Rank = 1;
	for (auto &t : V) {
		Set.insert(Z[K]);
		Set.erase(t);

		printf("? ");
		for (auto &t : Set)printf("%d ", t);
		puts("");
		fflush(stdout);
		scanf("%d%d", &a, &b);
		if (AA < b) {
			Rank++;
		}
		else if (AA > b) {

		}
		else if (AA == b) {
			if (w[Z[K]] < AA) {
				Rank++;
			}
			else {

			}
		}
		Set.insert(t);
		Set.erase(Z[K]);
	}
	printf("! %d\n", Rank);
	fflush(stdout);
}