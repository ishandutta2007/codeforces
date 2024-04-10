#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, M;
int mat[MAXN][MAXN];
vector <int> row[MAXN], col[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", mat[i] + j);
			row[i].push_back(mat[i][j]);
			col[j].push_back(mat[i][j]);
		}
}

void work(vector <int> &v) {
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

void solve() {
	for (int i = 0; i < MAXN; i++) {
		work(row[i]);
		work(col[i]);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x = lower_bound(row[i].begin(), row[i].end(), mat[i][j]) - row[i].begin();
			int y = lower_bound(col[j].begin(), col[j].end(), mat[i][j]) - col[j].begin();
			printf("%d ", max(x, y) + max((int)row[i].size() - x, (int)col[j].size() - y));
		}
		puts("");
	}
}

int main() {
	load();
	solve();
	return 0;
}