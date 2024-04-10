#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
int D[260][260][260],Nxt[101000][26];
char p[3][260], T[101000];
int n, Q, C[3];
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &Q);
	scanf("%s", T+1);
	int i, j, k, a;
	for (i = n; i >= 1; i--) {
		for (j = 0; j < 26; j++)Nxt[i][j] = Nxt[i + 1][j];
		Nxt[i][T[i] - 'a'] = i;
	}
	char ch[3], pp[3];
	while (Q--) {
		scanf("%s", ch);
		scanf("%d", &a);
		if (ch[0] != '-') {
			scanf("%s", pp);
		}
		a--;
		if (ch[0] == '+') {
			p[a][++C[a]] = pp[0];
			int be[3], ed[3];
			for (i = 0; i < 3; i++)be[i] = 0, ed[i] = C[i];
			be[a] = C[a];
			for (i = be[0]; i <= ed[0]; i++) {
				for (j = be[1]; j <= ed[1]; j++) {
					for (k = be[2]; k <= ed[2]; k++) {
						D[i][j][k] = 1e9;
						if (i && D[i - 1][j][k] < 8e8) {
							int t = Nxt[D[i - 1][j][k] + 1][p[0][i] - 'a'];
							if (t)D[i][j][k] = min(D[i][j][k], t);
						}
						if (j && D[i][j - 1][k] < 8e8) {
							int t = Nxt[D[i][j - 1][k] + 1][p[1][j] - 'a'];
							if (t)D[i][j][k] = min(D[i][j][k], t);

						}
						if (k && D[i][j][k-1] < 8e8) {
							int t = Nxt[D[i][j][k - 1] + 1][p[2][k] - 'a'];
							if (t)D[i][j][k] = min(D[i][j][k], t);

						}
					}
				}
			}
		}
		else {
			C[a]--;
		}
		if (D[C[0]][C[1]][C[2]] < 8e8)puts("YES");
		else puts("NO");
	}
}