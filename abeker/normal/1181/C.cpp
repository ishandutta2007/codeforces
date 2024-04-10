#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;

int N, M;
char mat[MAXN][MAXN];
int jmp[MAXN][MAXN], up[MAXN][MAXN];
int flag[MAXN][MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", mat[i]);
}

int hsh(string s) {
	int res = 0;
	for (auto it : s)
		res = 26 * res + it - 'a';
	return res;
}

ll solve() {
	memset(flag, -1, sizeof flag);
	
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == mat[i - 1][j])
				jmp[i][j] = jmp[i - 1][j];
			else
				jmp[i][j] = i - 1;
			up[i][j] = i - jmp[i][j];
		}
				
	for (int i = 1; i <= N; i++)	
		for (int j = 0; j < M; j++) {
			int nxt1 = jmp[i][j];
			if (!nxt1)
				continue;
			int nxt2 = jmp[nxt1][j];
			if (!nxt2)
				continue;
			if (up[i][j] != up[nxt1][j])
				continue;
			if (up[nxt2][j] < up[i][j])
				continue;
			flag[i][j] = hsh({mat[i][j], mat[nxt1][j], mat[nxt2][j]}) * MAXN + up[i][j];
		}
		
	ll sol = 0;
	for (int i = 1; i <= N; i++) {
		int streak = 0;
		for (int j = 0; j < M; j++) {
			if (j && (flag[i][j] == -1 || flag[i][j] != flag[i][j - 1]))
				streak = 0;		
			if (flag[i][j] != -1)
				sol += ++streak;
		}
	}
		
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}