#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 205;
const int MAXK = 14;

int N, M;
bool has[MAXN][1 << MAXK];
int pos[1 << MAXK][MAXK];
int pref[MAXN][MAXK], suff[MAXN][MAXK];
int len[MAXN];
vector <pii> all;

void init() {
	for (int i = 1; i < MAXK; i++)
		for (int j = 0; j < 1 << i; j++) {
			pos[j][i] = all.size();
			all.push_back({j, i});
		}	
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		char s[MAXN];
		scanf("%s", s);
		len[i] = strlen(s);
		for (int j = 1; j < MAXK; j++)
			for (int k = 0; k + j - 1 < len[i]; k++) {
				int mask = 0;
				for (int l = 0; l < j; l++)
					mask = 2 * mask + s[k + l] - '0';
				has[i][pos[mask][j]] = true;
			}
		for (int j = 0; j < len[i] && j + 1 < MAXK; j++)
			pref[i][j + 1] = 2 * pref[i][j] + s[j] - '0';
		for (int j = len[i] - 1; j >= 0 && len[i] - j < MAXK; j--)
			suff[i][len[i] - j] = suff[i][len[i] - j - 1] + (s[j] - '0') * (1 << len[i] - j - 1);   
	}
}

int merge(int a, int b, int c) {
	len[c] = min(len[a] + len[b], MAXK - 1);
	bool ok[MAXK];
	for (int i = 1; i < MAXK; i++)
		ok[i] = true;
	for (int i = 0; i < all.size(); i++) {
		if (has[a][i] || has[b][i]) {
			has[c][i] = true;
			continue;
		}
		for (int j = 1; j < all[i].second; j++) 
			if (all[i].second - j <= len[a] && j <= len[b] && (suff[a][all[i].second - j] << j) + pref[b][j] == all[i].first) {
				has[c][i] = true;
				break;
			}
		ok[all[i].second] &= has[c][i];
	}
	for (int i = 1; i <= len[c]; i++) {
		pref[c][i] = i > len[a] ? (pref[a][len[a]] << i - len[a]) + pref[b][i - len[a]] : pref[a][i];
		suff[c][i] = i > len[b] ? (suff[a][i - len[b]] << len[b]) + suff[b][len[b]] : suff[b][i]; 
	}
	for (int i = MAXK - 1; i; i--)
		if (ok[i])
			return i;
	return 0;
}

void solve() {
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", merge(a, b, N + i));
	}
}

int main() {
	init();
	load();
	solve();
	return 0;
}