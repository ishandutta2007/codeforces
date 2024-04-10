#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

void fwt_add(int* fwt, int x, int d) {
	x += 1;
	while (x <= MX) {
		fwt[x] += d;
		x += x & -x;
	}
}

int fwt_get(int* fwt, int x) {
	x += 1;
	int r = 0;
	while (x) {
		r += fwt[x];
		x -= x & -x;
	}
	
	return r;
}

int n, q, t[MX], l[MX], r[MX], ans[MX], len[MX];
char e[MX][11], s[MX];
int fwt[10][4][MX + 1];

void solve(int p) {
	memset(fwt, 0, sizeof fwt);
	for (int i = 0; i < n; i++) {
		fwt_add(fwt[i % p][s[i]], i, +1);
	}
	for (int i = 0; i < q; i++) {
		if (t[i] == 1) {
			int x = l[i];
			fwt_add(fwt[x % p][s[x]], x, -1);
			s[x] = e[i][0];
			fwt_add(fwt[x % p][s[x]], x, +1);
		}
		else if (len[i] == p) {
			for (int j = 0, rem = l[i] % p; j < p; j++, rem = (rem + 1) % p) {
				ans[i] += fwt_get(fwt[rem][e[i][j]], r[i]);
				ans[i] -= fwt_get(fwt[rem][e[i][j]], l[i] - 1);
			}
		}
	}
}

char tt[MX + 1];

int main() {
	ignore = scanf("%s %d", tt, &q);
	n = strlen(tt);
	for (int i = 0; i < q; i++) {
		ignore = scanf("%d %d", t + i, l + i);
		l[i]--;
		if (t[i] == 2) {
			ignore = scanf("%d", r + i);
			r[i]--;
		}
		
		ignore = scanf(" %s", e[i]);
		
		len[i] = 0;
		for (int j = 0; e[i][j] != 0; j++) {
			if (e[i][j] == 'A') e[i][j] = 0;
			if (e[i][j] == 'C') e[i][j] = 1;
			if (e[i][j] == 'G') e[i][j] = 2;
			if (e[i][j] == 'T') e[i][j] = 3;
			
			len[i]++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (tt[i] == 'A') tt[i] = 0;
		if (tt[i] == 'C') tt[i] = 1;
		if (tt[i] == 'G') tt[i] = 2;
		if (tt[i] == 'T') tt[i] = 3;
	}
	
	for (int i = 1; i <= 10; i++) {
		memcpy(s, tt, n);
		
		solve(i);
	}
	
	for (int i = 0; i < q; i++)
		if (t[i] == 2)
			printf("%d\n", ans[i]);
	
	return 0;
}