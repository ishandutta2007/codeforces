#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N, M;
char s[MAXN], t[MAXN];
int z[MAXN];
int cnt[2];
int pref[MAXN][2];

void load() {
	scanf("%s%s", t, s);
}

int get(int x, int y) {
	return pref[N - 1][y] - (x < N ? pref[N - x - 1][y] : 0);
}

void solve() {
	M = strlen(t);
	N = strlen(s);
	int L = 0, R = 0;
	for (int i = 1; i < N; i++) {
	  if (i > R) {
	    L = R = i;
	    while (R < N && s[R-L] == s[R]) R++;
	    z[i] = R-L; R--;
	  } else {
	    int k = i-L;
	    if (z[k] < R-i+1) z[i] = z[k];
	    else {
	      L = i;
	      while (R < N && s[R-L] == s[R]) R++;
	      z[i] = R-L; R--;
	    }
	  }
	}
	
	for (int i = 0; i < M; i++)
		cnt[t[i] - '0']++;
		
	for (int i = 0; i < N; i++) {
		if (i)
			for (int j = 0; j < 2; j++)
				pref[i][j] = pref[i - 1][j];
		pref[i][s[i] - '0']++;
	}
	
	for (int j = 0; j < 2; j++) {
		cnt[j] -= pref[N - 1][j];
		if (cnt[j] < 0) {
			puts(t);
			return;
		}
	}
		
	int sol = 0, best = 0;
	for (int i = 1; i <= N; i++) {
		if (z[i] < N - i)
			continue;
		int cand = MAXN;
		for (int j = 0; j < 2; j++) {
			int tmp = get(i, j);
			if (tmp)
				cand = min(cand, cnt[j] / tmp);
		}
		if (cand > sol) {
			sol = cand;
			best = i;
		}
	}
	
	printf("%s", s);
	for (int i = 0; i < sol; i++)
		for (int j = N - best; j < N; j++)
			printf("%c", s[j]);
	
	for (int j = 0; j < 2; j++) {
		int rest = cnt[j] - sol * get(best, j);
		while (rest--)
			printf("%d", j);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}