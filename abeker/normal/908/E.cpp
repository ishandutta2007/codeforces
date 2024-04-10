#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int M, N;
char s[MAXN];
ll mask[MAXN];
map <ll, int> cnt;
int part[MAXN];
int choose[MAXN][MAXN];

void load() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++)
			if (s[j] == '1')
				mask[j] |= 1ll << i;
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)	
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int solve() {
	choose[0][0] = 1;
	for (int i = 1; i <= M; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
	
	part[0] = 1;
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < i; j++)
			part[i] = add(part[i], mul(choose[i - 1][j], part[i - 1 - j]));
			
	for (int i = 0; i < M; i++)
		cnt[mask[i]]++;
	
	int sol = 1;
	for (auto it : cnt)
		sol = mul(sol, part[it.second]);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}