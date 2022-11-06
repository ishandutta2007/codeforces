#include <bits/stdc++.h>
using std::max; using std::min;
const int N = 100005;
int T, px, py, L;
char s[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &px, &py);
		scanf("%s", s); L = strlen(s);
		int x0 = 0, x1 = 0, y0 = 0, y1 = 0;
		for (int i = 0; i < L; i++) {
			if (s[i] == 'L') x0--;
			else if (s[i] == 'R') x1++;
			else if (s[i] == 'U') y1++;
			else y0--;
		}
		puts(x0 <= px && px <= x1 && y0 <= py && py <= y1 ? "YES" : "NO");
	}
	return 0;
}