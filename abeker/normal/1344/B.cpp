#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

class Counter {
	int cnt;
	int mini, maks;
public:
	Counter() {
		cnt = 0;
		mini = MAXN;
		maks = -1;
	}
	void update(int val) {
		mini = min(mini, val);
		maks = max(maks, val);
		cnt++;
	}
	bool empty() {
		return !cnt;
	}
	bool interval() {
		return empty() || cnt == maks - mini + 1;
	}
};

int N, M;
char mat[MAXN][MAXN];
Counter row[MAXN], col[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
}

bool black(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M && mat[x][y] == '#';
}

bool dfs(int x, int y) {
	if (!black(x, y))
		return false;
	mat[x][y] = '.';
	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x + 1, y);
	return true;
}

int solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (black(i, j)) {
				row[i].update(j);
				col[j].update(i);
			}
		
	bool emptyRow = false;
	for (int i = 0; i < N; i++) {
		emptyRow |= row[i].empty();
		if (!row[i].interval())
			return -1;
	}
	
	bool emptyCol = false;
	for (int j = 0; j < M; j++) {
		emptyCol |= col[j].empty();
		if (!col[j].interval())
			return -1;
	}
	
	if (emptyRow ^ emptyCol)
		return -1;
	
	int comps = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			comps += dfs(i, j);

	return comps;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}