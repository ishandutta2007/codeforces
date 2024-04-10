#include <bits/stdc++.h>

using namespace std;

char s[20][20], t[20][20];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) ignore = scanf("%s", s[i]);
	for (int i = 0; i < m; i++) ignore = scanf("%s", t[i]);
	
	int q;
	ignore = scanf("%d", &q);
	while (q--) {
		int y;
		ignore = scanf("%d", &y);
		y--;
		printf("%s%s\n", s[y % n], t[y % m]);
	}
	
	return 0;
}