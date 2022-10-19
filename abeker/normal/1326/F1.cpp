#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 15;

int N;
char mat[MAXN][MAXN];
int adj[MAXN][MAXN];
int cnt_lft[1 << MAXN][1 << MAXN / 2][MAXN];
int cnt_rig[1 << MAXN][1 << MAXN / 2][MAXN];
ll ans[1 << MAXN];
int lft, rig;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
}

void gen(int used, int pattern, int sofar, int where[1 << MAXN][1 << MAXN / 2][MAXN], int fst, int lst, bool flag) {
	if ((flag && sofar == rig) || (!flag && sofar == lft)) {
		where[used][pattern][flag ? fst : lst]++;
		return;
	}
	for (int i = 0; i < N; i++)
		if (!(used >> i & 1)) 
			gen(used | 1 << i, fst == -1 ? 0 : pattern | (adj[lst][i] << sofar - 1), sofar + 1, where, fst == -1 ? i : fst, i, flag);
}

void calc(int l, int r) {
	vector <int> vl, vr;
	for (int i = 0; i < N; i++)
		if (l >> i & 1)
			vl.push_back(i);
		else
			vr.push_back(i);
	for (int a = 0; a < 1 << lft - 1; a++)
		for (int b = 0; b < 1 << rig - 1; b++)
			for (int i = 0; i < lft; i++)
				if (cnt_lft[l][a][vl[i]])
					for (int j = 0; j < rig; j++)
						if (cnt_rig[r][b][vr[j]])
							ans[a | (adj[vl[i]][vr[j]] << lft - 1) | (b << lft)] += (ll)cnt_lft[l][a][vl[i]] * cnt_rig[r][b][vr[j]];
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			adj[i][j] = mat[i][j] - '0';
	lft = (N + 1) / 2;
	rig = N / 2;
	gen(0, 0, 0, cnt_lft, -1, -1, 0);
	gen(0, 0, 0, cnt_rig, -1, -1, 1);
	for (int i = 0; i < 1 << N; i++)
		if (__builtin_popcount(i) == lft)
			calc(i, (1 << N) - 1 ^ i);
	for (int i = 0; i < 1 << N - 1; i++)
		printf("%lld ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}