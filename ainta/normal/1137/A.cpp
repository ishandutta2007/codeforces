#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, w[1010][1010];
int A[1010][1010], B[1010][1010], C[1010][1010], D[1010][1010];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		vector<int>T;
		for (j = 1; j <= m; j++) {
			T.push_back(w[i][j]);
		}
		sort(T.begin(), T.end());
		T.resize(unique(T.begin(), T.end()) - T.begin());
		int sz = T.size();
		for (j = 1; j <= m; j++) {
			int pv = lower_bound(T.begin(), T.end(), w[i][j]) - T.begin();
			A[i][j] = pv;
			B[i][j] = sz - 1 - pv;
		}
	}
	for (i = 1; i <= m; i++) {
		vector<int>T;
		for (j = 1; j <= n; j++) {
			T.push_back(w[j][i]);
		}
		sort(T.begin(), T.end());
		T.resize(unique(T.begin(), T.end()) - T.begin());
		int sz = T.size();
		for (j = 1; j <= n; j++) {
			int pv = lower_bound(T.begin(), T.end(), w[j][i]) - T.begin();
			C[j][i] = pv;
			D[j][i] = sz - 1 - pv;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d ", max(A[i][j],C[i][j])+max(B[i][j],D[i][j]) + 1);
		}
		puts("");
	}
}