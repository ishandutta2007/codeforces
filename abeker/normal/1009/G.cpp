#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
char s[MAXN];
int mask[MAXN];
int disj[MAXN][1 << 6];
int cnt[10];

void load() {
	scanf("%s%d", s, &M);
	while (M--) {
		int pos;
		char buff[10];
		scanf("%d%s", &pos, buff);
		for (int i = 0; buff[i]; i++)
			mask[pos - 1] |= 1 << buff[i] - 'a';
	}
}

bool can(int pos, int ltr) {
	if (!cnt[ltr])
		return false;
	if (mask[pos] && !(mask[pos] >> ltr & 1))
		return false;
	
	cnt[ltr]--;
	for (int i = 0; i < 1 << 6; i++) {
		int sum = disj[pos + 1][i];
		for (int j = 0; j < 6; j++)
			if (i >> j & 1)
				sum += cnt[j];
		if (sum > N - pos - 1) {
			cnt[ltr]++;
			return false;
		}
	}
	
	return true;		
}

void solve() {
	N = strlen(s);
	
	for (int i = N - 1; i >= 0; i--) {
		cnt[s[i] - 'a']++;
		for (int j = 0; j < 1 << 6; j++)
			disj[i][j] = disj[i + 1][j] + (mask[i] && !(mask[i] & j));
	}
	
	for (int i = 0; i < N; i++) {
		bool ok = false;
		for (int j = 0; j < 6; j++)
			if (can(i, j)) {
				printf("%c", 'a' + j);
				ok = true;
				break;
			}
		if (!ok) {
			puts("Impossible");
			return;
		}
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}