#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1.5e6 + 5;
const int INF = 1e9;
const string ltr = "*onetw";

struct state {
	int x, y, z;
};

int N;
char s[MAXN];
int dp[2][6][6];
bool take[MAXN][6][6];
bool bad[6][6][6];
int idx[30];

void load() {
	scanf("%s", s);
}

void solve() {
	N = strlen(s);
	
	int row = 0;
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 6; b++)
			dp[row][a][b] = 0;
	
	for (int pos = N - 1; pos >= 0; pos--) {
		row ^= 1;
		for (int a = 0; a < 6; a++)
			for (int b = 0; b < 6; b++) {
				int &ref = dp[row][a][b];
				ref = dp[row ^ 1][a][b];
				take[pos][a][b] = false;
				int c = idx[s[pos] - 'a'];
				if (!bad[a][b][c]) {
					int tmp = dp[row ^ 1][b][c] + 1;
					if (tmp > ref) {
						ref = tmp;
						take[pos][a][b] = true;
					}
				}	
			}
	}
	
	int ans = dp[row][0][0];
	vector <bool> used(N, false);
	state curr = {0, 0, 0};
	for (int i = 0; i < N; i++) {
		used[curr.x] = take[curr.x][curr.y][curr.z];
		if (used[curr.x])
			curr = {curr.x + 1, curr.z, idx[s[curr.x] - 'a']};
		else
			curr.x++;
	}
	
	printf("%d\n", N - ans);
	for (int i = 0; i < N; i++)
		if (!used[i])
			printf("%d ", i + 1);
	puts("");
}

void init() {
	for (int i = 1; i < 6; i++)
		idx[ltr[i] - 'a'] = i;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++) {
				string tmp = "";
				for (auto it : {i, j, k})
					tmp += ltr[it];
				bad[i][j][k] = tmp == "one" || tmp == "two";
			}
}

int main() {
	init();
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}