#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e3 + 5;

int N, M;
int score[MAXN];
int deg1[MAXN], deg2[MAXN];
int tour1[MAXN][MAXN], tour2[MAXN][MAXN];
pii sorted[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", score + N - i);	
}

void bye() {
	puts("no");
	exit(0);
}

void decrease(pii arr[MAXN], int mat[MAXN][MAXN], int lo, int hi, int who) {
	for (int i = lo; i <= hi; i++) {
		mat[arr[i].second][arr[who].second] = 1;
		arr[i].first--;
	}
}

void construct(int deg[MAXN], int result[MAXN][MAXN]) {
	for (int i = 1; i <= N; i++)
		sorted[i] = {deg[i], i};
	sort(sorted + 1, sorted + N + 1);
	for (int i = N; i; i--) {
		int tmp = i - 1 - sorted[i].first;
		if (tmp) {
			int lft = i - tmp, rig = i - tmp;
			while (lft > 1 && sorted[lft].first == sorted[lft - 1].first)
				lft--;
			while (rig < i - 1 && sorted[rig].first == sorted[rig + 1].first)
				rig++;
			decrease(sorted, result, rig + 1, i - 1, i);
			decrease(sorted, result, lft, lft + rig - i + tmp, i);
		}
		for (int j = 1; j < i; j++)
			result[sorted[i].second][sorted[j].second] = result[sorted[j].second][sorted[i].second] ^ 1;
	}
}

void solve() {
	int tot = N * (N - 1);
	for (int i = 0; i < M; i++)
		tot -= score[N - i];
	if (tot < 0)
		bye();
	for (int i = 0; i < N - M; i++)
		score[N - M - i] = tot / (N - M) + (i < tot % (N - M));
	
	if (score[N - M] > score[N - M + 1])
		bye();
		
	int pref = 0, odd = 0;
	for (int i = 1; i <= N; i++) {
		pref += score[i];
		if (pref < i * (i - 1))
			bye();
		deg1[i] = score[i] / 2;
		deg2[i] = (score[i] + 1) / 2;
		odd += score[i] % 2;
		if (odd % 2)
			swap(deg1[i], deg2[i]);
	}
	
	construct(deg1, tour1);
	construct(deg2, tour2);
		
	puts("yes");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%c", i == j ? 'X' : "LDW"[tour1[i][j] + tour2[i][j]]);
		puts("");
	}
}

int main() {
	load();
	solve();
	return 0;
}