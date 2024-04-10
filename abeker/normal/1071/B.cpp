#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;

int N, K;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN];
bool bad[MAXN][MAXN];
bool bio[MAXN][MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%s", mat[i] + 1);
}

bool ok(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}

bool valid(int x, int y, char c) {
	return ok(x, y) && mat[x][y] == c && !bio[x][y];
}

void solve() {
	memset(dp, INF, sizeof dp);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			bad[i][j] = mat[i][j] != 'a';
	
	int mx = 0;
	dp[0][1] = dp[1][0] = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + bad[i][j];
			if (bad[i][j] && dp[i][j] <= K + 1)
				mx = max(mx, i + j);
		}
	
	if (dp[N][N] <= K) {
		for (int i = 0; i < 2 * N - 1; i++)
			printf("a");
		puts("");
		return;
	}
	
	vector <pii> tmp;
	char mn = 'z' + 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (bad[i][j] && dp[i][j] <= K + 1 && i + j == mx) {
				tmp.push_back({i, j});
				mn = min(mn, mat[i][j]);
			}
	
	vector <pii> curr;
	for (auto it : tmp)
		if (mat[it.first][it.second] == mn)
			curr.push_back(it);
	
	for (int i = 0; i < mx - 2; i++)
		printf("a");
		
	while (!curr.empty()) {
		printf("%c", mat[curr.back().first][curr.back().second]);
		char mn = 'z' + 1;
		for (auto it : curr) {
			if (ok(it.first + 1, it.second))
				mn = min(mn, mat[it.first + 1][it.second]);
			if (ok(it.first, it.second + 1))
				mn = min(mn, mat[it.first][it.second + 1]);
		}
		vector <pii> nxt;
		for (auto it : curr) {
			if (valid(it.first + 1, it.second, mn)) {
				nxt.push_back({it.first + 1, it.second});
				bio[it.first + 1][it.second] = true;
			}
			if (valid(it.first, it.second + 1, mn)) {
				nxt.push_back({it.first, it.second + 1});
				bio[it.first][it.second + 1] = true;
			}
		}
		curr = nxt;
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}