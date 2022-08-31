#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[160000];
int D[160000][6][6], Path[160000][6][6];
int n, w[160000];
void Solve() {
	int i, j, k;
	scanf("%s", p + 1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	for (i = 1; i <= n; i++) {
		if (p[i] == 'o') {
			w[i] = 1;
		}
		else if (p[i] == 'n') {
			w[i] = 2;
		}
		else if (p[i] == 'e') {
			w[i] = 3;
		}
		else if (p[i] == 't') {
			w[i] = 4;
		}
		else if (p[i] == 'w') {
			w[i] = 5;
		}
		else {
			w[i] = 0;
		}
	}
	for (i = 0; i <= n; i++)for (j = 0; j < 6; j++)for (k = 0; k < 6; k++)D[i][j][k] = 1e9;
	D[0][0][0] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 6; k++) {
				if (D[i-1][j][k] > 8e8)continue;
				if (D[i][j][k] > D[i - 1][j][k] + 1){
					D[i][j][k] = D[i - 1][j][k] + 1;
					Path[i][j][k] = -1;
				}
				if (j == 1 && k == 2 && w[i] == 3)continue;
				if (j == 4 && k == 5 && w[i] == 1)continue;
				if (D[i][k][w[i]] > D[i - 1][j][k]) {
					D[i][k][w[i]] = D[i - 1][j][k];
					Path[i][k][w[i]] = j;
				}
			}
		}
	}
	int Mn = 1e9, x, y;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (Mn > D[n][i][j]) {
				x = i, y = j;
				Mn = D[n][i][j];
			}
		}
	}
	vector<int>Ans;
	for (i = n; i >= 1; i--) {
		if (Path[i][x][y] == -1) {
			Ans.push_back(i);
			continue;
		}
		int t = Path[i][x][y];
		y = x;
		x = t;
	}
	printf("%d\n", Ans.size());
	if (!Ans.empty()) {
		reverse(Ans.begin(), Ans.end());
		for (auto &t : Ans)printf("%d ", t);
	}
	puts("");
}
int main() {
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}