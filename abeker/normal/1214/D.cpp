#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, M;
string mat[MAXN];
char buff[MAXN];
vector <bool> bio1[MAXN], bio2[MAXN];
int cnt[2 * MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", buff);
		mat[i] = buff;
	}
}

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M && mat[x][y] == '.';
}

void dfs1(int x, int y) {
	if (!ok(x, y) || bio1[x][y])
		return;
	bio1[x][y] = true;
	dfs1(x + 1, y);
	dfs1(x, y + 1);
}

void dfs2(int x, int y) {
	if (!ok(x, y) || bio2[x][y])
		return;
	bio2[x][y] = true;
	dfs2(x - 1, y);
	dfs2(x, y - 1);
}

int solve() {
	for (int i = 0; i < N; i++) {
		bio1[i].resize(M);
		bio2[i].resize(M);
	}
	
	dfs1(0, 0);
	dfs2(N - 1, M - 1);

	if (!bio2[0][0])
		return 0;
	
	for (int i = 0; i < N; i++)	
		for (int j = 0; j < M; j++)
			if (bio1[i][j] && bio2[i][j])
				cnt[i + j]++;
	
	for (int i = 1; i < N + M - 2; i++)
		if (cnt[i] == 1)
			return 1;
	
	return 2;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}