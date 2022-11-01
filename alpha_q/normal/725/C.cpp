#include <bits/stdc++.h>
 
using namespace std;

const int N = 40;

char s[N], g[4][N];

void print (void) {
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j <= 13; ++j) cout << g[i][j];
		puts("");
	}
}

int main (int argc, char const *argv[]) {
	scanf("%s", s + 1);
	int n = 27;

	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 13; ++j)
			g[i][j] = '#';

	for (int i = 1; i < n; ++i)
		if (s[i] == s[i + 1]) {
			puts("Impossible");
			return 0;
		}

	int dist = -1, from, to;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			if (s[i] == s[j]) {
				from = i, to = j, dist = j - i - 1;
				break;
			}
		if (dist != -1) break;
	}

	// cout << dist << endl;

	int gap = dist >> 1;
	int uppos = 13 - gap;
	g[1][uppos] = s[from];

	int x = from + 1, up = uppos + 1;
	while (up <= 13 and x < to) g[1][up] = s[x], ++up, ++x;
	int down = 13;
	while (x < to) g[2][down] = s[x], --down, ++x;
	
	x = from - 1;
	while (down >= 1 and x >= 1) g[2][down] = s[x], --down, --x;
	up = 1;
	while (x >= 1) g[1][up] = s[x], ++up, --x;

	x = 27;
	while (down >= 1 and x > to) g[2][down] = s[x], --down, --x;
	while (x > to) g[1][up] = s[x], --x, ++up;

	print();	
	return 0;
}