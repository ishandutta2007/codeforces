#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define pii pair<int,int>
using namespace std;
vector<string> w;
vector<vector<int>> D[4], DD, S;
int n, m;
char p[1010000];
void Add(int bx, int by, int ex, int ey) {
	bx = max(bx, 0);
	by = max(by, 0);
	ex = min(ex, n);
	ey = min(ey, m);
	S[bx][by]++, S[ex][by]--, S[bx][ey]--, S[ex][ey]++;
}
bool OK(int a) {
	int i, j;
	for (i = 0; i < n; i++)for (j = 0; j < m; j++)S[i][j] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (DD[i][j] >= a) {
				Add(i - a + 1, j - a + 1, i + a, j + a);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			S[i][j] += S[i][j - 1];
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			S[i][j] += S[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)for (j = 0; j < m; j++)if (w[i][j] == 'X' && !S[i][j])return false;
	return true;
}
void Print(int K) {
	printf("%d\n", K - 1);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (DD[i][j] >= K) {
				printf("X");
			}
			else printf(".");
		}

		puts("");
	}

}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", p);
		w.push_back(p);
	}
	for (i = 0; i < 4; i++) {
		D[i].resize(n);
		for (j = 0; j < n; j++)D[i][j].resize(m);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (w[i][j] == '.')continue;
			if (i == 0 || j == 0)D[0][i][j] = 1;
			else D[0][i][j] = min({ D[0][i][j - 1], D[0][i - 1][j], D[0][i - 1][j - 1] }) + 1;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = m - 1; j >= 0; j--) {
			if (w[i][j] == '.')continue;
			if (i == 0 || j == m-1)D[1][i][j] = 1;
			else D[1][i][j] = min({ D[1][i][j + 1], D[1][i - 1][j],D[1][i - 1][j + 1] }) + 1;
		}
	}
	for (i = n-1; i >= 0; i--) {
		for (j = 0; j < m; j++) {
			if (w[i][j] == '.')continue;
			if (i == n-1 || j == 0)D[2][i][j] = 1;
			else D[2][i][j] = min({ D[2][i][j - 1], D[2][i + 1][j],D[2][i + 1][j - 1] }) + 1;
		}
	}
	for (i = n-1; i >= 0; i--) {
		for (j = m - 1; j >= 0; j--) {
			if (w[i][j] == '.')continue;
			if (i == n-1 || j == m - 1)D[3][i][j] = 1;
			else D[3][i][j] = min({ D[3][i][j + 1], D[3][i + 1][j],D[3][i + 1][j + 1] }) + 1;
		}
	}
	DD.resize(n);
	S.resize(n+1);
	for (i = 0; i <= n; i++)S[i].resize(m + 1);
	for (i = 0; i < n; i++) {
		DD[i].resize(m);
		for (j = 0; j < m; j++) {
			DD[i][j] = 1e9;
			for (int k = 0; k < 4; k++)DD[i][j] = min(DD[i][j], D[k][i][j]);
		}
	}
	int b = 1, e = min(n, m), mid, r = 0;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (OK(mid)) {
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	Print(r);
}