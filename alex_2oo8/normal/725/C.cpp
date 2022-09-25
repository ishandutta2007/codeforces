#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

char s[MX + 1], g[2][14];
int a[26];

int main() {
	scanf(" %s", s);
	
	for (int i = 0; i < 26; i++) a[i] = -1;
	
	int x, y;
	for (int i = 0; i < 27; i++) {
		s[27 + i] = s[i];
		
		if (a[s[i] - 'A'] == -1) {
			a[s[i] - 'A'] = i;
			
			continue;
		}
		
		x = a[s[i] - 'A'];
		y = i;
	}
	
	if (y - x == 1) {
		printf("Impossible\n");
		
		return 0;
	}
	
	if ((y - x) % 2 == 0) {
		int f = (y - x) / 2;
		
		for (int i = 13 - f, j = 0; i < 13; i++, j++) {
			g[0][i] = s[x + f + f - 1 - j];
			g[1][i] = s[x + j];
		}
		
		for (int i = 13 - f - 1, j = 0; i >= 0; i--, j++) {
			g[0][i] = s[y + 1 + j];
			g[1][i] = s[y + 13 - f + 13 - f - j];
		}
	}
	else {
		int f = (y - x + 1) / 2;
		
		for (int i = 13 - f, j = 0; i < 13; i++, j++) {
			g[0][i] = s[x + f + f - 1 - j];
			g[1][i] = s[x + j];
		}
		
		for (int i = 13 - f, j = 0; i >= 0; i--, j++) {
			g[0][i] = s[y + 1 + j];
			g[1][i] = s[y + 13 - f + 13 - f + 2 - j];
		}
	}
	
	printf("%s\n%s\n", g[0], g[1]);
	
	return 0;
}