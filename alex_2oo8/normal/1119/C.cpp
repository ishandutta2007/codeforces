#include <bits/stdc++.h>

using namespace std;

const int MX = 500;

int r[MX], c[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int it = 0; it < 2; it++)
		for (int i = 0; i < n; i++)
			for (int j = 0, x; j < m; j++) {
				ignore = scanf("%d", &x);
				r[i] ^= x;
				c[j] ^= x;
			}
	
	bool ok = true;
	for (int i = 0; i < n; i++) ok = ok && r[i] == 0;
	for (int i = 0; i < m; i++) ok = ok && c[i] == 0;
	
	printf("%s\n", ok ? "Yes" : "No");
	
	return 0;
}