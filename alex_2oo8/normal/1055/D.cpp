#include <bits/stdc++.h>

using namespace std;

const int MX = 3000;

void no() {
	printf("%s\n", "NO");
	exit(0);
}

char s[2 * MX][MX + 1];
char x[MX + 1], y[MX + 1];

int l[MX], r[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) ignore = scanf(" %s", s[i]);
	
	for (int i = 0; i < n; i++) {
		l[i] = r[i] = -1;
		for (int j = 0; s[i][j] != 0; j++) {
			if (s[i][j] == s[i + n][j]) continue;
			if (l[i] == -1) l[i] = j;
			r[i] = j;
		}
	}
	
	int f = 0;
	while (l[f] == -1) f++;
	
	for (int i = 0; i < n; i++) {
		if (l[i] == -1) continue;
		
		if (r[i] - l[i] != r[f] - l[f]) no();
		
		for (int j = l[i], k = l[f]; j <= r[i]; j++, k++) {
			if (s[i][j] != s[f][k]) no();
			if (s[n + i][j] != s[n + f][k]) no();
		}
	}
	
	{	
		bool ok = true;
		while (s[f][r[f] + 1] != 0 && ok) {
			for (int i = 0; i < n && ok; i++) ok = l[i] == -1 || s[i][r[i] + 1] == s[f][r[f] + 1];
			for (int i = 0; i < n && ok; i++) ok = l[i] == -1 || s[n + i][r[i] + 1] == s[n + f][r[f] + 1];
			if (ok) {
				for (int i = 0; i < n; i++) if (l[i] != -1) r[i]++;
			}
		}
	}
	
	{	
		bool ok = true;
		while (l[f] > 0 && ok) {
			for (int i = 0; i < n && ok; i++) ok = l[i] == -1 || (l[i] > 0 && s[i][l[i] - 1] == s[f][l[f] - 1]);
			for (int i = 0; i < n && ok; i++) ok = l[i] == -1 || (l[i] > 0 && s[n + i][l[i] - 1] == s[n + f][l[f] - 1]);
			if (ok) {
				for (int i = 0; i < n; i++) if (l[i] != -1) l[i]--;
			}
		}
	}
	
	memcpy(x, s[f] + l[f], r[f] - l[f] + 1);
	memcpy(y, s[n + f] + l[f], r[f] - l[f] + 1);
	
	for (int i = 0; i < n; i++) {
		static char str[2 * MX + 1];
		int len = 0;
		for (int j = 0; x[j] != 0; j++) str[len++] = x[j];
		str[len++] = '@';
		for (int j = 0; s[i][j] != 0; j++) str[len++] = s[i][j];
		
		static int kmp[2 * MX + 1];
		kmp[0] = 0;
		for (int p = 1; p < len; p++) {
			int j = kmp[p - 1];
			while (j > 0 && str[p] != str[j]) j = kmp[j - 1];
			kmp[p] = j + (str[p] == str[j] ? 1 : 0);
			if (kmp[p] == r[f] - l[f] + 1) {
				for (int j = p - 2 * (r[f] - l[f] + 1), k = 0; x[k] != 0; j++, k++) {
					assert(s[i][j] == x[k]);
					s[i][j] = y[k];
				}
				break;
			}
		}
		
		for (int j = 0; s[i][j] != 0; j++) if (s[i][j] != s[n + i][j]) no();
	}
	
	printf("%s\n%s\n%s\n", "YES", x, y);
	
	return 0;
}