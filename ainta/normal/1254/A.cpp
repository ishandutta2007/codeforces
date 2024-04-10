#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, K, C[110], M[110];
char p[110][110], Res[110][110];
char Trans(int a) {
	if (a < 10)return a + '0';
	a -= 10;
	if (a < 26)return a + 'A';
	a -= 26;
	return a + 'a';
}
void Solve() {
	int i, j, cnt = 0;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
		for (j = 1; j <= m; j++) {
			if (p[i][j] == 'R') {
				cnt++;
			}
		}
	}
	for (i = 0; i < K; i++) {
		M[i] = cnt / K;
		if (i < cnt%K)M[i]++;
		C[i] = 0;
	}
	int cur = 0;
	for (i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (j = 1; j <= m; j++) {
				if (p[i][j] == 'R') {
					if (C[cur] == M[cur])cur++;
					C[cur]++;
				}
				Res[i][j] = Trans(cur);
			}
		}
		else {
			for (j = m; j >= 1; j--) {
				if (p[i][j] == 'R') {
					if (C[cur] == M[cur])cur++;
					C[cur]++;
				}
				Res[i][j] = Trans(cur);
			}
		}
		for (j = 1; j <= m; j++)printf("%c", Res[i][j]);
		puts("");
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}