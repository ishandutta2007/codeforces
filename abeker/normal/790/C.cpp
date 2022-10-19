#include <bits/stdc++.h>
using namespace std;

const int MAXN = 80;
const int INF = 1e9;

int N;
char s[MAXN];
int ltr[MAXN];
int dp[MAXN][MAXN][MAXN][3][3];
vector <int> pos[MAXN];
int nxt[MAXN][3];
int idx[MAXN];

void load() {
	scanf("%d%s", &N, s);
}

int rec(vector <int> cnt, int prv, int curr) {
	int x = 0;
	for (auto it : cnt) {
		if (it < 0)
			return INF;
		x += it;
	}
	int &ref = dp[cnt[0]][cnt[1]][cnt[2]][prv][curr];
	if (ref != -1)
		return ref;
	ref = INF;
	if (prv == 1 && curr == 0)
		return ref;
	if (--cnt[prv] < 0 || --cnt[curr] < 0)
		return ref;
	cnt[prv]++;
	if (x == 2) 
		return ref = pos[prv][0] > pos[curr][0];
	for (int i = 0; i < 3; i++) 
		ref = min(ref, rec(cnt, i, prv));
	for (int i = 0; i < 3; i++)
		if (i != curr)
			ref += max(cnt[i] - idx[nxt[pos[curr][cnt[curr]]][i]], 0);
	return ref;
}

int solve() {
	if (N == 1)
		return 0;
		
	memset(dp, -1, sizeof dp);
	
	for (int i = 0; i < N; i++) {
		if (s[i] == 'K')
			ltr[i] = 0;
		else if (s[i] == 'V')
			ltr[i] = 1;
		else
			ltr[i] = 2;
		idx[i] = pos[ltr[i]].size();
		pos[ltr[i]].push_back(i);
	}
	
	idx[N] = N;
	for (int i = 0; i < 3; i++)
		nxt[N][i] = N;
	for (int i = N - 1; i >= 0; i--) {
		memcpy(nxt[i], nxt[i + 1], sizeof nxt[i]);
		nxt[i][ltr[i]] = i;
	}
	
	vector <int> occ(3);
	for (int i = 0; i < 3; i++)
		occ[i] = pos[i].size();
	
	int sol = INF;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sol = min(sol, rec(occ, i, j));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}